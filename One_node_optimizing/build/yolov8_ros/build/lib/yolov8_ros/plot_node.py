from cv_bridge import CvBridge
import cv2
from rclpy.node import Node
from ultralytics.utils.plotting import Annotator, colors
from sensor_msgs.msg import Image
from rclpy.qos import qos_profile_sensor_data
from yolov8_msgs.msg import DetectionArray
from yolov8_msgs.msg import Objects
import numpy as np
import rclpy
import message_filters
from rclpy.qos import QoSProfile
from rclpy.qos import QoSHistoryPolicy
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSReliabilityPolicy




class PlotNode(Node) :
    
    def __init__(self) -> None :
            super().__init__("plot_node")
            self.declare_parameter("image_reliability",QoSReliabilityPolicy.BEST_EFFORT)
            self.image_qos_profile = QoSProfile(
                reliability=self.get_parameter(
                    "image_reliability").get_parameter_value().integer_value,
                history=QoSHistoryPolicy.KEEP_LAST,
                durability=QoSDurabilityPolicy.VOLATILE,
                depth=1
            )

            self.cv_bridge = CvBridge()

            self.image_sub = message_filters.Subscriber(
                self, Image, "image_raw", qos_profile=self.image_qos_profile)
            self.detections_sub = message_filters.Subscriber(
                self, DetectionArray, "detections_3d", qos_profile=10)
    
            
            self._synchronizer = message_filters.ApproximateTimeSynchronizer(
                (self.image_sub, self.detections_sub), 10, 0.5)
            self._synchronizer.registerCallback(self.image_cb)

                

    def image_cb(self, img_msg : Image, detection_msg : DetectionArray) -> None :

        cv_image = self.cv_bridge.imgmsg_to_cv2(img_msg)
          
        annotator = Annotator(cv_image, line_width=1, font_size=8)
                

        # for detection, object in zip(detection_msg.detections,object_track_msg.objects):
        for detection in detection_msg.detections:
            
            # self.get_logger().info(f"Detection : {detection} \n")
            mask_msg = detection.mask
            mask_array = np.array([[int(ele.x), int(ele.y)] for ele in mask_msg.data])
            # self.get_logger().info(f"{mask_array}")
            label = str(detection.class_name)
            score = detection.score
            track_id = detection.id
            if track_id is not None and mask_array is not None:
                # if  label == "person" :
                annotator.seg_bbox(mask=mask_array, mask_color=colors(track_id, True), label=label + str(round(score,2)))



            # if results[0].boxes.id is not None and results[0].masks is not None:
            #         result = results[0]
            #         masks = result.masks.xy
            #         track_ids = result.boxes.id.int().cpu().tolist()
            #         clss = result.boxes.cls.tolist()
            #         confs = result.boxes.conf.tolist()
            #         for mask, track_id, cls, conf in zip(masks, track_ids, clss, confs):
            #             if self.yolo.names[cls] == 'person':
            #                 annotator.seg_bbox(mask=mask, mask_color=colors(track_id, True), det_label=self.yolo.names[cls] + str(round(conf,2)))

        
        cv2.imshow('result',cv2.cvtColor(cv_image, cv2.COLOR_BGR2RGB))
        cv2.waitKey(1)

    
def main():

    rclpy.init()
    node = PlotNode()
    rclpy.spin(node)
    node.destroy_node()
    cv2.destroyAllWindows()
    rclpy.shutdown()