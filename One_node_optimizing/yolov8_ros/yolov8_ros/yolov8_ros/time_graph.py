import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from rclpy.qos import QoSProfile
from rclpy.qos import QoSHistoryPolicy
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSReliabilityPolicy
import time
from yolov8_msgs.msg import DetectionArray
from yolov8_msgs.msg import Objects
import cv2
import numpy as np

class TimeGraphNode(Node):

    def __init__(self) -> None :
        super().__init__("time_graph_node")
        self.image_qos_profile = QoSProfile(
                reliability=QoSReliabilityPolicy.BEST_EFFORT,
                history=QoSHistoryPolicy.KEEP_LAST,
                durability=QoSDurabilityPolicy.VOLATILE,
                depth=1
            )
        self._sub = self.create_subscription(Image,"image_raw",self.original_cb ,qos_profile=self.image_qos_profile)
        self._yolo_sub = self.create_subscription(DetectionArray,"detections_3d",self.yolo_cb,10)
        self._depth_sub = self.create_subscription(Image,"depth_image",self.depth_cb,qos_profile=self.image_qos_profile)
        self._mota_sub = self.create_subscription(Objects,"mot_objects",self.mota_cb,10)

        self.previous_time = time.time()
        self.present_time = 0
        self.a_yolo_time = 0 
        self.b_yolo_time = 0 
        self.a_depth_time = 0
        self.b_depth_time = 0
        self.a_mota_time = 0
        self.b_mota_time = 0


        self.yolo_i = 50
        self.color_i = 50
        self.depth_i = 50
        self.mota_i = 50
        self.alpha_depth_i = 0
        self.alpha_yolo_i = 0
        self.alpha_color_i = 0 
        self.alpha_mota_i = 0
        self.window = (640, 480)
        self.color_frame = self.createimage(self.window[0], self.window[1])
        self.yolo_frame = self.createimage(self.window[0], self.window[1])
        self.depth_frame = self.createimage(self.window[0], self.window[1])
        self.mota_frame = self.createimage(self.window[0],self.window[1])
        self.plot_axes(self.color_frame)
        self.plot_axes(self.yolo_frame)
        self.plot_axes(self.depth_frame)
        self.plot_axes(self.mota_frame)
        cv2.imshow('color frame',self.color_frame)
        cv2.imshow('yolo frame',self.yolo_frame)
        cv2.imshow('depth frame',self.depth_frame)
        cv2.imshow('MOTA frame',self.mota_frame)
        cv2.moveWindow('color frame', 640, 0)
        cv2.moveWindow('yolo frame', 1280, 0)
        cv2.moveWindow('depth frame', 640, 960)
        cv2.moveWindow('MOTA frame', 1280, 960)
        self.yolo_plot_list = []
        self.color_plot_list = []
        self.depth_plot_list = []
        self.mota_plot_list = []
        self.yolo_frame_list = []
        self.color_frame_list = []
        self.depth_frame_list = []
        self.mota_frame_list = []

    def createimage(self,w,h):
        # shape = (h, w, 1)
        img = np.ones((h,w,3),np.uint8)*255
        return img

    def original_cb(self,img) -> None :
        
        self.previous_time = self.present_time
        self.present_time = time.time()
        _exe_time = self.present_time - self.previous_time
        exe_time = _exe_time * 1000
        i = self.color_i -50
        a = self.alpha_color_i

        y_position = int(self.window[1]-30-exe_time)
        if self.color_i != 50 :
            # 점
            cv2.circle(self.color_frame,(i*2+50,y_position),2,(0,0,0),-1)
            # y 값 [ms]
            if int(exe_time) % 5 == 0 and int(exe_time) not in self.color_plot_list:
                cv2.putText(self.color_frame,str(int(exe_time)),(8,y_position),1,0.6,(0,0,0),1)
                self.color_plot_list.append(int(exe_time))
            # x frame
            if  (i+a) % 5 == 0 and (i+a) not in self.color_frame_list : 
                for n, char in enumerate(str((i+a))) : 
                        cv2.putText(self.color_frame,char,(i*2+50,self.window[1]-20 + n*10),1,0.6,(0,0,0),1)
                self.color_frame_list.append((i+a))

        cv2.imshow('color frame',self.color_frame)
        
        if cv2.waitKey(1) & 0xFF == ord('q'):
            rclpy.shutdown()
            cv2.destroyAllWindows()

        self.color_i += 1
        if (i*2+50) >= self.window[0]:
            self.alpha_color_i += i
            self.color_i = 50  # Reset x position after reaching the window width
            self.color_frame = self.createimage(self.window[0], self.window[1])
            self.plot_axes(self.color_frame)  # Redraw axes after resetting

    def yolo_cb(self,msg) -> None :

        self.a_yolo_time = self.b_yolo_time
        self.b_yolo_time = time.time()
        _exe_time = self.b_yolo_time - self.a_yolo_time
        exe_time = _exe_time*1000   # ms unit
        i = self.yolo_i - 50
        a = self.alpha_yolo_i

        y_position = int(self.window[1]-30-exe_time)
        if self.yolo_i != 50 :
            cv2.circle(self.yolo_frame,(i*2+50,y_position),2,(0,0,255),-1)
            
            if int(exe_time) % 5 == 0 and int(exe_time) not in self.yolo_plot_list :
                cv2.putText(self.yolo_frame,str(int(exe_time)),(8,y_position),1,0.6,(0,0,255),1)
                self.yolo_plot_list.append(int(exe_time))

            if  (i+a) % 5 == 0 and (i+a) not in self.yolo_frame_list : 
                for n, char in enumerate(str((i+a))) : 
                        cv2.putText(self.yolo_frame,char,(i*2+50,self.window[1]-20 + n*10),1,0.6,(0,0,0),1)
                self.yolo_frame_list.append((i+a))


        cv2.imshow('yolo frame',self.yolo_frame)
        
        if cv2.waitKey(1) & 0xFF == ord('q'):
            rclpy.shutdown()
            cv2.destroyAllWindows()

        self.yolo_i += 1


        if (i*2+50) >= self.window[0]:
            self.alpha_yolo_i += i
            self.yolo_i = 50  # Reset x position after reaching the window width
            self.yolo_frame = self.createimage(self.window[0], self.window[1])
            self.plot_axes(self.yolo_frame)  # Redraw axes after resetting


    def depth_cb(self,msg) -> None :

        self.a_depth_time = self.b_depth_time
        self.b_depth_time = time.time()
        _exe_time= self.b_depth_time - self.a_depth_time
        exe_time = _exe_time*1000 # ms unit
        i = self.depth_i - 50
        a = self.alpha_depth_i

        y_position = int(self.window[1]-30-exe_time)
        if self.depth_i != 50 :
            cv2.circle(self.depth_frame,(i*2+50,y_position),2,(0,255,0),-1)
        
            if int(exe_time) % 5 == 0 and int(exe_time) not in self.depth_plot_list :
                cv2.putText(self.depth_frame,str(int(exe_time)),(8,y_position),1,0.6,(0,255,0),1)
                self.depth_plot_list.append(int(exe_time))
            
            if  (i+a) % 5 == 0 and (i+a) not in self.depth_frame_list : 
                for n, char in enumerate(str(i+a)) : 
                        cv2.putText(self.depth_frame,char,(i*2+50,self.window[1]-20 + n*10),1,0.6,(0,0,0),1)
                self.depth_frame_list.append(i+a)

        cv2.imshow('depth frame',self.depth_frame)
        
        if cv2.waitKey(1) & 0xFF == ord('q'):
            rclpy.shutdown()
            cv2.destroyAllWindows()

        self.depth_i += 1
        if (i*2+50) >= self.window[0]-50:
            self.alpha_depth_i += i
            self.depth_i = 50  # Reset x position after reaching the window width
            self.depth_frame = self.createimage(self.window[0], self.window[1])
            self.plot_axes(self.depth_frame)  # Redraw axes after resetting

    def mota_cb(self,msg) :
        
        self.a_mota_time = self.b_mota_time
        self.b_mota_time = time.time()
        _exe_time = self.b_mota_time - self.a_mota_time
        exe_time = _exe_time*1000 # ms unit
        i = self.mota_i -50
        a = self.alpha_mota_i

        y_position = int(self.window[1]-30-exe_time)

        if self.mota_i != 50 :
            cv2.circle(self.mota_frame,(i*2+50,y_position),2,(0,127,127),-1)

            if int(exe_time) % 5 == 0 and int(exe_time) not in self.mota_plot_list :
                cv2.putText(self.mota_frame,str(int(exe_time)),(8,y_position),1,0.6,(0,127,127),1)
                self.mota_plot_list.append(int(exe_time))

            if  (i+a) % 5 == 0 and (i+a) not in self.mota_frame_list : 
                for n, char in enumerate(str(i+a)) : 
                        cv2.putText(self.mota_frame,char,(i*2+50,self.window[1]-20 + n*10),1,0.6,(0,0,0),1)
                self.mota_frame_list.append(i+a)


        cv2.imshow('MOTA frame',self.mota_frame)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            rclpy.shutdown()
            cv2.destroyAllWindows()

        self.mota_i += 1

        

        if (i*2+50) >= self.window[0]-50:
            self.alpha_mota_i += i
            self.mota_i = 50  # Reset x position after reaching the window width
            self.mota_frame = self.createimage(self.window[0], self.window[1])
            self.plot_axes(self.mota_frame)  # Redraw axes after resetting

    def plot_axes(self,frame) :

        # draw axis
        cv2.line(frame, (50,0),(50,self.window[1]), (0,0,0),1) 
        cv2.line(frame, (0,self.window[1]-30),(self.window[0],self.window[1]-30), (0,0,0),1) 
        cv2.putText(frame,"[ms]",(8,15),1,1,(0,0,0),1)
        cv2.putText(frame,"frames",(self.window[0]-60,self.window[1]-8),1,1,(0,0,0),1)
        y66_position = int (self.window[1]-30-66)
        y100_position = int (self.window[1]-30-100)
        cv2.line(frame,(0,y66_position),(self.window[0],y66_position),(255,0,0),1)
        cv2.line(frame,(0,y100_position),(self.window[0],y100_position),(0,0,255),1)



    def mota_plot_axes(self,frame) :

        # draw axis
        cv2.line(frame, (50,0),(50,self.window[1]), (0,0,0),1) 
        cv2.line(frame, (0,self.window[1]-30),(self.window[0],self.window[1]-30), (0,0,0),1) 
        cv2.putText(frame,"[ms]",(8,15),1,1,(0,0,0),1)
        cv2.putText(frame,"frames",(self.window[0]-60,self.window[1]-8),1,1,(0,0,0),1)
        y66_position = int (self.window[1]-30-100)
        cv2.line(frame,(0,y66_position),(self.window[0],y66_position),(255,0,0),1)


def main():
    rclpy.init()
    node = TimeGraphNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__=='__main__':
    main()