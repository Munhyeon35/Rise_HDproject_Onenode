
import cv2
import torch
import random
from time import time
import numpy as np

from typing import List, Dict

import rclpy
from rclpy.qos import qos_profile_sensor_data, QoSProfile, QoSHistoryPolicy, QoSDurabilityPolicy, QoSReliabilityPolicy
from rclpy.node import Node
from cv_bridge import CvBridge

from ultralytics import YOLO
from ultralytics.engine.results import Results
from ultralytics.engine.results import Boxes
from ultralytics.engine.results import Masks
from ultralytics.engine.results import Keypoints

from ultralytics import YOLO
from ultralytics.trackers import BOTSORT, BYTETracker
from ultralytics.trackers.basetrack import BaseTrack
from ultralytics.utils import IterableSimpleNamespace, yaml_load
from ultralytics.utils.checks import check_requirements, check_yaml
from ultralytics.utils.plotting import Annotator, colors



import message_filters
from std_srvs.srv import SetBool
from sensor_msgs.msg import Image, CameraInfo
from yolov8_msgs.msg import Point2D
from yolov8_msgs.msg import BoundingBox2D
from yolov8_msgs.msg import Mask
from yolov8_msgs.msg import KeyPoint2D
from yolov8_msgs.msg import KeyPoint2DArray
from yolov8_msgs.msg import Detection
from yolov8_msgs.msg import DetectionArray
from yolov8_msgs.msg import BoundingBox3D
from yolov8_msgs.msg import SegmentCenters


class Yolov8Node(Node):

    def __init__(self) -> None:
        super().__init__("yolov8_node")

        # params
        self.declare_parameter("model", "yolo11n-seg.pt")
        self.model = self.get_parameter(
            "model").get_parameter_value().string_value      

        self.declare_parameter("device", "cpu") # "cuda:0"
        self.device = self.get_parameter(
            "device").get_parameter_value().string_value

        self.declare_parameter("threshold", 0.5)
        self.threshold = self.get_parameter(
            "threshold").get_parameter_value().double_value

        self.declare_parameter("enable", True)
        self.enable = self.get_parameter(
            "enable").get_parameter_value().bool_value
        
        self.declare_parameter("topic_name","/camera/camera/color/image_raw")
        self.topic_name = self.get_parameter("topic_name").get_parameter_value().string_value

        self.declare_parameter("maximum_detection_threshold", 0.3)
        self.maximum_detection_threshold = self.get_parameter(
            "maximum_detection_threshold").get_parameter_value().double_value
        
        self.declare_parameter("depth_image_units_divisor", 1000)
        self.depth_image_units_divisor = self.get_parameter(
            "depth_image_units_divisor").get_parameter_value().integer_value

        

        self.cv_bridge = CvBridge()
        self.yolo = YOLO(self.model)
        # Code for Segmentation mode.
        #self.yolo = YOLO("yolov8m-seg.pt") 
        
        self.yolo.fuse()
        self.yolo.to(self.device)

        self.depth_image_qos_profile = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            history=QoSHistoryPolicy.KEEP_LAST,
            durability=QoSDurabilityPolicy.VOLATILE,
            depth=1
        )

        self.depth_info_qos_profile = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            history=QoSHistoryPolicy.KEEP_LAST,
            durability=QoSDurabilityPolicy.VOLATILE,
            depth=1
        )
    
        
        # topcis
        self._pub = self.create_publisher(DetectionArray, "detections_3d", 10)
        self._mot_pub = self.create_publisher(SegmentCenters, "SegmentCenters", 10)        


        self.color_sub = message_filters.Subscriber(
            self, Image, self.topic_name,
            qos_profile=qos_profile_sensor_data
        )
        self.depth_sub = message_filters.Subscriber(
            self, Image, "depth_image",
            qos_profile=self.depth_image_qos_profile)
        self.depth_info_sub = message_filters.Subscriber(
            self, CameraInfo, "depth_info",
            qos_profile=self.depth_info_qos_profile)

        self._synchronizer = message_filters.ApproximateTimeSynchronizer(
            (self.color_sub, self.depth_sub, self.depth_info_sub), 10, 0.5)
        self._synchronizer.registerCallback(self.image_cb)


        # services
        self._srv = self.create_service(SetBool, "enable", self.enable_cb)


    def enable_cb(self,
                  req: SetBool.Request,
                  res: SetBool.Response
                  ) -> SetBool.Response:
        self.enable = req.data
        res.success = True
        return res
    
    def parse_hypothesis(self, results: Results) -> List[Dict]:

        hypothesis_list = []

        box_data: Boxes
        for box_data in results.boxes:
            hypothesis = {
                "class_id": int(box_data.cls),
                "class_name": self.yolo.names[int(box_data.cls)],
                "score": float(box_data.conf)
            }
            hypothesis_list.append(hypothesis)

        return hypothesis_list

    def parse_boxes(self, results: Results) -> List[BoundingBox2D]:

        boxes_list = []

        box_data: Boxes
        for box_data in results.boxes:

            msg = BoundingBox2D()

            # get boxes values
            box = box_data.xywh[0]
            msg.center.position.x = float(box[0])
            msg.center.position.y = float(box[1])
            msg.size.x = float(box[2])
            msg.size.y = float(box[3])

            # append msg
            boxes_list.append(msg)

        return boxes_list

    def parse_masks(self, results: Results) -> List[Mask]:

        masks_list = []

        def create_point2d(x: float, y: float) -> Point2D:
            p = Point2D()
            p.x = x
            p.y = y
            return p

        mask: Masks
        for mask in results.masks:

            msg = Mask()

            msg.data = [create_point2d(float(ele[0]), float(ele[1]))
                        for ele in mask.xy[0].tolist()]
            msg.height = results.orig_img.shape[0]
            msg.width = results.orig_img.shape[1]

            masks_list.append(msg)

        return masks_list

    def parse_keypoints(self, results: Results) -> List[KeyPoint2DArray]:

        keypoints_list = []

        points: Keypoints
        for points in results.keypoints:

            msg_array = KeyPoint2DArray()

            if points.conf is None:
                continue

            for kp_id, (p, conf) in enumerate(zip(points.xy[0], points.conf[0])):

                if conf >= self.threshold:
                    msg = KeyPoint2D()

                    msg.id = kp_id + 1
                    msg.point.x = float(p[0])
                    msg.point.y = float(p[1])
                    msg.score = float(conf)

                    msg_array.data.append(msg)

            keypoints_list.append(msg_array)

        return keypoints_list

    def process_detections(
        self,
        depth_msg: Image,
        depth_info_msg: CameraInfo,
        detections_msg: DetectionArray
    ) -> List[Detection]:

        # check if there are detections
        if not detections_msg.detections:
            return []

        # transform = self.get_transform(depth_info_msg.header.frame_id)

        # if transform is None:
        #     return []

        new_detections = []
        depth_image = self.cv_bridge.imgmsg_to_cv2(depth_msg)

        for detection in detections_msg.detections:
            bbox3d = self.convert_bb_to_3d(
                depth_image, depth_info_msg, detection)

            if bbox3d is not None:
                new_detections.append(detection)
                # bbox3d = Detect3DNode.transform_3d_box(
                #     bbox3d, transform[0], transform[1])
                # bbox3d.frame_id = self.target_frame
                new_detections[-1].bbox3d = bbox3d


        return new_detections

    def convert_bb_to_3d(
        self,
        depth_image: np.ndarray,
        depth_info: CameraInfo,
        detection: Detection
    ) -> BoundingBox3D:


        center_x = int(detection.bbox.center.position.x)
        center_y = int(detection.bbox.center.position.y)
        size_x = int(detection.bbox.size.x)
        size_y = int(detection.bbox.size.y)

        if detection.mask.data:
            # crop depth image by mask
            mask_array = np.array([[int(ele.x), int(ele.y)]
                                   for ele in detection.mask.data])
            mask = np.zeros(depth_image.shape[:2], dtype=np.uint8)
            cv2.fillPoly(mask, [np.array(mask_array, dtype=np.int32)], 255)
            roi = cv2.bitwise_and(depth_image, depth_image, mask=mask)         ## roi : depth이미지에서 mask부분만 픽셀 값이 유지되고 나머지는 0.

        else:
            # crop depth image by the 2d BB
            u_min = max(center_x - size_x // 2, 0)
            u_max = min(center_x + size_x // 2, depth_image.shape[1] - 1)
            v_min = max(center_y - size_y // 2, 0)
            v_max = min(center_y + size_y // 2, depth_image.shape[0] - 1)

            roi = depth_image[v_min:v_max, u_min:u_max]          ## bb면 그 박스 안에만 픽셀 값 유지

        roi = roi / self.depth_image_units_divisor  # convert to meters
        if not np.any(roi):
            return None

        # find the z coordinate on the 3D BB
        if detection.mask.data:
            roi = roi[roi > 0]              ## mask부분만 추출
            bb_center_z_coord = np.median(roi)      ## mask의 depth 값 중에 중앙값 찾기

        else:
            bb_center_z_coord = depth_image[int(center_y)][int(       
                center_x)] / self.depth_image_units_divisor

#                 File "/home/rise/ref_yolov8/install/yolov8_ros/lib/python3.10/site-packages/yolov8_ros/detect_3d_node.py", line 230, in convert_bb_to_3d
# [detect_3d_node-3]     bb_center_z_coord = depth_image[int(center_y)][int(       #
# [detect_3d_node-3] IndexError: index 410 is out of bounds for axis 0 with size 400


        z_diff = np.abs(roi - bb_center_z_coord)             ## 중앙값에서 거리가 threshold 내에 있는 값이 유효값이므로 이 값들만 추출. 
        mask_z = z_diff <= self.maximum_detection_threshold         ## mask에서 유의미한 부분만 가져온다. ex) 물체 주변이 masking 되면 이 데이터는 bb_center_z_coord와 차이가 커서 제거 
        if not np.any(mask_z):
            return None

        roi = roi[mask_z]                   ## mask_z는 bool 배열 
        z_min, z_max = np.min(roi), np.max(roi)
        z = (z_max + z_min) / 2                 ## 유효값의 산술평균을 z값으로 결정

        if z == 0:
            return None

        # project from image to world space
        k = depth_info.k
        px, py, fx, fy = k[2], k[5], k[0], k[4]             ## 카메라 매트릭스 : px,py 중심점; fx, fy 초점거리;
        x = z * (center_x - px) / fx                ## x는 카메라 중심점으로 부터 거리 [m]
        y = z * (center_y - py) / fy
        w = z * (size_x / fx)
        h = z * (size_y / fy)
        
        # [detect_3d_node-3] [INFO] [1723531589.508180384] [yolo.detect_3d_node]: px : 318.77581787109375
        # [detect_3d_node-3] fx : 477.2984313964844
        # [detect_3d_node-3] center_x : 119
        # [detect_3d_node-3] z : 1.926
        # [detect_3d_node-3] x : -0.8061376277604096
        # [detect_3d_node-3] 


        # create 3D BB
        msg = BoundingBox3D()
        msg.center.position.x = x
        msg.center.position.y = y
        msg.center.position.z = z 
        msg.size.x = w
        msg.size.y = h
        msg.size.z = float(z_max - z_min)

        return msg

    def show_cb(self, msg: Image) -> Node : 
        
        if self.enable: 
            cv_image = self.cv_bridge.imgmsg_to_cv2(msg)
            cv2.imshow('result',cv2.cvtColor(cv_image, cv2.COLOR_BGR2RGB))
            cv2.waitKey(1)



    def image_cb(self, msg: Image, 
                 depth_msg: Image,
                depth_info_msg: CameraInfo,
    ) -> None:

        if self.enable:

            # convert image + predict
            cv_image = self.cv_bridge.imgmsg_to_cv2(msg)
            

            annotator = Annotator(cv_image, line_width=1, font_size=8)

            results = self.yolo.predict(
                source=cv_image,
                verbose=False,
                stream=False,
                conf=self.threshold,
                # persist=True,
                classes = [0,26,28,39,41,56,62,63,67],
            )
            

            #Segmentation with boundary line.
            # if results[0].boxes.id is not None and results[0].masks is not None:
            #     result = results[0]
            #     masks = result.masks.xy
            #     track_ids = result.boxes.id.int().cpu().tolist()
            #     clss = result.boxes.cls.tolist()
            #     confs = result.boxes.conf.tolist()
            #     for mask, track_id, cls, conf in zip(masks, track_ids, clss, confs):
            #         if self.yolo.names[cls] == 'person':
            #             annotator.seg_bbox(mask=mask, mask_color=colors(track_id, True), label=self.yolo.names[cls] + str(round(conf,2)))


            results: Results = results[0].cpu()

            if results.boxes:
                hypothesis = self.parse_hypothesis(results)
                boxes = self.parse_boxes(results)

            if results.masks:
                masks = self.parse_masks(results)

            if results.keypoints:
                keypoints = self.parse_keypoints(results)

            # create detection msgs
            detections_msg = DetectionArray()

            for i in range(len(results)):

                aux_msg = Detection()

                if results.boxes:
                    aux_msg.class_id = hypothesis[i]["class_id"]
                    aux_msg.class_name = hypothesis[i]["class_name"]
                    aux_msg.score = hypothesis[i]["score"]

                    aux_msg.bbox = boxes[i]

                if results.masks:
                    aux_msg.mask = masks[i]

                if results.keypoints:
                    aux_msg.keypoints = keypoints[i]

                detections_msg.detections.append(aux_msg)

            # publish detections
            detections_msg.header = msg.header

            # 3d
            new_detections_msg = DetectionArray()
            segment_centers_msg = SegmentCenters()
            new_detections_msg.header = detections_msg.header
            segment_centers_msg.header = detections_msg.header
            new_detections_msg.detections = self.process_detections(
            depth_msg, depth_info_msg, detections_msg)

            # segmentation msg
            
            for detection in new_detections_msg.detections : 

                segment_centers_msg.id.append(detection.class_id)
                segment_centers_msg.pixel_x.append(int(detection.bbox.center.position.x))
                segment_centers_msg.pixel_y.append(int(detection.bbox.center.position.y))
                segment_centers_msg.x.append(detection.bbox3d.center.position.x)
                segment_centers_msg.y.append(detection.bbox3d.center.position.y)
                segment_centers_msg.z.append(detection.bbox3d.center.position.z)
                # segment_centers_msg.secs.append(self.get_clock().now().seconds_nanoseconds()[0])  ### 시간이 고정되어 출력된다.
                segment_centers_msg.secs.append(time()) 

            self._mot_pub.publish(segment_centers_msg)
            self._pub.publish(new_detections_msg)
            
            # plot for segmentation
            # cv2.imshow('result',cv2.cvtColor(cv_image, cv2.COLOR_BGR2RGB))

            del results
            del cv_image



        cv2.waitKey(1)



def main():
    rclpy.init()
    node = Yolov8Node()
    rclpy.spin(node)
    rclpy.shutdown()
