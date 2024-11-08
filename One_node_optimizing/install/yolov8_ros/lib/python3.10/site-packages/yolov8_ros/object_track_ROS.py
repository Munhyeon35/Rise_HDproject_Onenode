#!/usr/bin/env python2
import numpy as np 
import cv2
import time
import rclpy
from rclpy.node import Node
import argparse
import random

from yolov8_ros.tracker import Tracker
from yolov8_msgs.msg import SegmentCenters
from yolov8_msgs.msg import ObjTracking
from yolov8_msgs.msg import Objects
from visualization_msgs.msg import Marker, MarkerArray

from rclpy.qos import QoSProfile
from rclpy.qos import QoSHistoryPolicy
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSReliabilityPolicy

class MotNode(Node) :

	''' SegmentCenters.msg
	Header header
	int16[] id
	int16[] pixel_x
	int16[] pixel_y
	float64[] x : Moving right in respect to camera
	float64[] y : Moving up in respect to camera
	float64[] z : Moving away from camera
	float64[] secs
	'''

	''' objTracking.msg
	Header header
	int16 object_id
	geometry_msgs/Point pos      # Central point [m]
	geometry_msgs/Vector3 vel  # Linear velocity [m/s]
		'''

	tracker = Tracker(150, 10, 5) # dist_threshold : for 150 pixel distance can be same obj, max_frame_skipped : frame time-to-live, max_trace_length : trace until num

	# def str2bool(v):
	#     if v.lower() in ('yes', 'true', 't', 'y', '1'):
	#         return True
	#     elif v.lower() in ('no', 'false', 'f', 'n', '0'):
	#         return False
	#     else:
	#         raise argparse.ArgumentTypeError('Boolean value expected.')

	# def parse_args(argv=None):
	#     parser = argparse.ArgumentParser(
	# 						description='mot argument parser')
	#     parser.add_argument('--cam_fixed',
	# 	 					dest="cam_fixed", type=str2bool, help='Whether or not to use a camera fixed or attached to a robot')
	#     parser.add_argument('--fixed_cam_frame_id',
	# 	 					dest="fixed_cam_frame_id", type=str, help='Frame ID of fixed camera')
	#     parser.add_argument('--robot_cam_frame_id',
	# 						dest="robot_cam_frame_id", type=str, help='Frame ID of attached camera')

	#     parser.set_defaults(cam_fixed=True, fixed_cam_frame_id="camera_link", robot_cam_frame_id="base_link")

	#     global args
	#     args0 = rospy.myargv()
	#     args = parser.parse_args(args0[1:])

	def __init__(self) -> None :
		super().__init__('mot_node')
		self.declare_parameter("camera_link", "camera_link") 							
		self.camera_link = self.get_parameter("camera_link").get_parameter_value().string_value   
		self.image_qos_profile = QoSProfile(
            reliability=QoSReliabilityPolicy.BEST_EFFORT,
            history=QoSHistoryPolicy.KEEP_LAST,
            durability=QoSDurabilityPolicy.VOLATILE,
            depth=1
        ) 
		self._pub = self.create_publisher(Objects, "mot_objects", 1000)
		self._sub = self.create_subscription(SegmentCenters, "SegmentCenters", self.bird_eyed_view_tracking, qos_profile=self.image_qos_profile)


	def createimage(self,w,h):
		# shape = (h, w, 1)
		img = np.ones((h,w,3),np.uint8)*255
		return img

	def vel(self, current,before)-> float:
		duration = current[3]-before[3]
		if duration == 0 : 
			v = (0.0,0.0,0.0)
			return v
		vx = (current[0]-before[0])/duration
		vy = (current[1]-before[1])/duration
		vz = (current[2]-before[2])/duration
		v = (self.rd(vx),self.rd(vy),self.rd(vz))
		return v

	def rd(self,f) -> float:
		mul = 10000
		if f<0:
			return 0.0
		ret = f*mul
		ret = round(ret)
		ret /= mul
		return ret

	def mapping(self,x,z,window):
		# 1 pixel = 0.01m = 10mm
		bias_x = window[0]//2
		bias_z = window[1]-120      ## 40
		cv_x = int(x*100) + bias_x
		cv_z = -int(z*100) + bias_z
		return cv_x, cv_z

	def print_position(self,str,position):
		print(str)
		print("x :",position[0])
		print("y :",position[1])
		print("z :",position[2])
		print("sec :",position[3])

	def bird_eyed_view_tracking(self, msg):
		# SegmentCenters must be a center points of each frame
		centers_list = []
		states_list = []
		msg_id = msg.id
		msg_pixel_x = msg.pixel_x
		msg_pixel_y = msg.pixel_y
		msg_x = msg.x
		msg_y = msg.y
		msg_z = msg.z
		msg_secs = msg.secs
		# window = (1080,960)
		window = (960,640)
		objects = Objects()
		objects.header.frame_id = self.camera_link            ## modified
		# self.get_logger().info(f"z Information : {msg.z}\n")  #####

		if len(msg_id)==0: # published none value msg
			return

		for i in range(len(msg_x)):
			# if msg_id[i] != 0: # Only detect for person
			# 	continue
			if msg_x[i]==0 and msg_y[i]==0 and msg_z[i]==0: # Detecting errors in depth camera
				continue
			cv_x, cv_z = self.mapping(msg_x[i],msg_z[i],window) 
			# self.get_logger().info(f"After Mapping : {cv_z}\n")  #####
			centers_list.append([cv_x, cv_z])
			states_list.append([msg_x[i], msg_y[i], msg_z[i], msg_secs[i], msg_id[i]])    ## 241104 [msg_x[i], msg_y[i], msg_z[i], msg_secs[i]]
		centers = np.array(centers_list) 
		states = np.array(states_list)

		# global tracker

		skip_frame_count = 0
		track_colors = [(255, 0, 0), (0, 255, 0), (0, 0, 255), (255, 255, 0),
						(127, 127, 255), (255, 0, 255), (255, 127, 255),
						(127, 0, 255), (127, 0, 127),(127, 10, 255), (0,255, 127)]

		frame = self.createimage(window[0],window[1]) # height, width
		
		self.tracker.update(centers, states)
		# self.get_logger().info(f"MOTA : {self.tracker.calculate_MOTA()}\n")           #33333##########3

		# draw axis
		# cv2.line(frame, (window[0]//2,0),(window[0]//2,window[1]), (0,0,0),1) 
		# cv2.line(frame, (window[0]//2,0),(window[0]//2-10,10), (0,0,0),1)
		# cv2.putText(frame,"z(m)", (window[0]//2+20,20),0, 0.5, (0,0,0),2)
		# cv2.line(frame, (0,window[1]-40),(window[0],window[1]-40), (0,0,0),1)
		# cv2.line(frame, (window[0]-10,window[1]-30),(window[0],window[1]-40), (0,0,0),1)
		# cv2.putText(frame,"x(m)", (window[0]-40,window[1]-20),0, 0.5, (0,0,0),2)

		# draw units on axis in 1 meter (1pixel = 10mm, 100 pixel = 1m)
		# for i in range(int(window[0]/100)):
		# 	cv2.line(frame, (window[0]//2+i*100,window[1]-50),(window[0]//2+i*100,window[1]-30), (0,0,0),1)
		# 	# indicate a scale of x axis
		# 	cv2.putText(frame, str(i), (window[0]//2+i*100+10,window[1]-20),0, 0.5, (0,0,0))
		# 	cv2.line(frame, (window[0]//2-i*100,window[1]-50),(window[0]//2-i*100,window[1]-30), (0,0,0),1)
		# 	# indicate a scale of x axis
		# 	cv2.putText(frame, str(-i), (window[0]//2-i*100+10,window[1]-20),0, 0.5, (0,0,0))
		# for i in range(int(window[1]/100)):
		# 	if i == 0:
		# 		continue
		# 	cv2.line(frame, (window[0]//2-10,window[1]-40-i*100),(window[0]//2+10,window[1]-40-i*100),(0,0,0),1)
		# 	# indicate a scale of z axis
		# 	cv2.putText(frame, str(i), (window[0]//2+20,window[1]-40-i*100),0, 0.5, (0,0,0))

		for j in range(len(self.tracker.tracks)):
			if (len(self.tracker.tracks[j].trace) > 1):
				# bird-eyed-view visualization
				cv_x = int(self.tracker.tracks[j].trace[-1][0,0])
				cv_z = int(self.tracker.tracks[j].trace[-1][0,1])
				cv_tl = (cv_x-10,cv_z-10)
				cv_br = (cv_x+10,cv_z+10)
				for k in range(len(self.tracker.tracks[j].trace)):
					x_k = self.tracker.tracks[j].trace_state[k][0,0]
					z_k = self.tracker.tracks[j].trace_state[k][0,2]
					cv_x_k, cv_z_k = self.mapping(x_k, z_k,window)	

					if k >= len(self.tracker.tracks[j].trace) - 5:
						# show last 5 points to black, for indicating the trajectory
						cv2.circle(frame,(cv_x_k,cv_z_k), 3, [0,0,0],-1)
					else:
						cv2.circle(frame,(cv_x_k,cv_z_k), 3, track_colors[j],-1)
				
				state_current = self.tracker.tracks[j].trace_state[-1]
				position_current = (state_current[0,0],state_current[0,1],state_current[0,2],state_current[0,3])

				state_before = self.tracker.tracks[j].trace_state[-2]
				position_before = (state_before[0,0],state_before[0,1],state_before[0,2],state_before[0,3])

				if position_current[0] == position_before[0]:
					self.tracker.tracks[j].is_updated = False
				else:
					self.tracker.tracks[j].is_updated = True

				# print_position("position_current",position_current)
				# print_position("position_before",position_before)
				velocity = self.vel(position_current,position_before)

				# publish infos 
				# print("=============================")
				# print(self.tracker.tracks[j].trackId)
				# print(position_current)
				# print(velocity)
				if self.tracker.tracks[j].is_updated:
					msg = ObjTracking()
					msg.header.frame_id = self.camera_link			## modified
					msg.object_id = self.tracker.tracks[j].trackId
					msg.pos.x = position_current[2]
					msg.pos.y = -position_current[0]
					msg.pos.z = position_current[1]
					msg.vel.x = velocity[2]
					msg.vel.y = -velocity[0]
					msg.vel.z = velocity[1]
					objects.objects.append(msg)
				# cv2.rectangle(frame,cv_tl,cv_br,track_colors[j],1)
				# cv2.putText(frame,str(self.tracker.tracks[j].trackId), (cv_x-10,cv_z-20),0, 0.5, track_colors[j],2)
				# cv2.putText(frame,"vel = ("+str(velocity[0])+", "+str(velocity[2])+")", (cv_x+10,cv_z-20),0, 0.5, track_colors[j],2)
				# cv2.circle(frame,(cv_x,cv_z), 3, (0,0,0),-1)

		# cv2.imshow('image',frame)
		self._pub.publish(objects)
			
		# if cv2.waitKey(1) & 0xFF == ord('q'):
		# 	cv2.destroyAllWindows()

	def forward_view_tracking(self, msg):
		# SegmentCenters must be a center points of each frame
		centers_list = []
		states_list = []
		msg_id = msg.id
		msg_pixel_x = msg.pixel_x
		msg_pixel_y = msg.pixel_y
		msg_x = msg.x
		msg_y = msg.y
		msg_z = msg.z
		msg_secs = msg.secs
		objects = Objects()

		if len(msg_id)==0: # published none value msg
			return

		for i in range(len(msg_x)):
			if msg_id[i] != 0: # Only detect for person
				continue
			if msg_x[i]==0 and msg_y[i]==0 and msg_z[i]==0: # Detecting errors in depth camera
				continue
			centers_list.append([msg_pixel_x[i],msg_pixel_y[i]])
			states_list.append([msg_x[i], msg_y[i], msg_z[i], msg_secs[i]])
		centers = np.array(centers_list) 
		states = np.array(states_list)

		# global tracker

		skip_frame_count = 0
		track_colors = [(255, 0, 0), (0, 255, 0), (0, 0, 255), (255, 255, 0),
						(127, 127, 255), (255, 0, 255), (255, 127, 255),
						(127, 0, 255), (127, 0, 127),(127, 10, 255), (0,255, 127)]
		window = (640,480)
		frame = self.createimage(window[0],window[1])
		
		self.tracker.update(centers, states)



		for j in range(len(self.tracker.tracks)):
			if (len(self.tracker.tracks[j].trace) > 1):
				vel_flag=False
				pixel_x = int(self.tracker.tracks[j].trace[-1][0,0])
				pixel_y = int(self.tracker.tracks[j].trace[-1][0,1])

				x = self.tracker.tracks[j].trace_state[-1][0,0]
				y = self.tracker.tracks[j].trace_state[-1][0,1]
				z = self.tracker.tracks[j].trace_state[-1][0,2]
				sec = self.tracker.tracks[j].trace_state[-1][0,3]
				current = (x,y,z,sec)
				current_rd = (self.rd(x),self.rd(y),self.rd(z),self.rd(sec%100))

				pixel_x_0 = int(self.tracker.tracks[j].trace[-2][0,0])
				pixel_y_0 = int(self.tracker.tracks[j].trace[-2][0,1])

				x_b = self.tracker.tracks[j].trace_state[-2][0,0]
				y_b = self.tracker.tracks[j].trace_state[-2][0,1]
				z_b = self.tracker.tracks[j].trace_state[-2][0,2]
				sec_b = self.tracker.tracks[j].trace_state[-2][0,3]
				before = (x_b, y_b,z_b,sec_b)

				velocity = self.vel(current, before)

				tl = (pixel_x-10,pixel_y-10)
				br = (pixel_x+10,pixel_y+10)

				# frame based visualization
				cv2.rectangle(frame,tl,br,track_colors[j],1)
				cv2.putText(frame,str(self.tracker.tracks[j].trackId), (pixel_x-10,pixel_y-20),0, 0.5, track_colors[j],2)
				for k in range(len(self.tracker.tracks[j].trace)):
					pixel_x_k = int(self.tracker.tracks[j].trace[k][0,0])
					pixel_y_k = int(self.tracker.tracks[j].trace[k][0,1])	

					cv2.circle(frame,(pixel_x_k,pixel_y_k), 3, track_colors[j],-1)

				cv2.line(frame, (pixel_x,pixel_y),(pixel_x_0,pixel_y_0), (0,100,0),3)
				cv2.putText(frame,"vel :"+str(velocity), (pixel_x+10,pixel_y+20),0, 0.5, (0,200,0),2)
				cv2.putText(frame,"pos :"+str(current_rd),(pixel_x+10,pixel_y+40),0,0.5, (0,200,0),2)

				cv2.circle(frame,(pixel_x,pixel_y), 6, track_colors[j],-1)
				cv2.circle(frame,(pixel_x,pixel_y), 6, (0,0,0),-1)

				# If you want to see the result in bird-eyed-view, uncomment below and comment #frame based visualization
				'''
				# draw axis
				cv2.line(frame, (window[0]/2,0),(window[0]/2,window[1]), (0,0,0),1) 
				cv2.line(frame, (window[0]/2,0),(window[0]/2-10,10), (0,0,0),1)
				cv2.putText(frame,"z(m)", (window[0]/2+20,20),0, 0.5, (0,0,0),2)
				cv2.line(frame, (0,window[1]-40),(window[0],window[1]-40), (0,0,0),1)
				cv2.line(frame, (window[0]-10,window[1]-30),(window[0],window[1]-40), (0,0,0),1)
				cv2.putText(frame,"x(m)", (window[0]-40,window[1]-20),0, 0.5, (0,0,0),2)

				# draw units on axis in 1 meter (1pixel = 10mm, 100 pixel = 1m)
				for i in range(int(window[0]/100)):
					cv2.line(frame, (window[0]/2+i*100,window[1]-50),(window[0]/2+i*100,window[1]-30), (0,0,0),1)
					cv2.line(frame, (window[0]/2-i*100,window[1]-50),(window[0]/2-i*100,window[1]-30), (0,0,0),1)
				for i in range(int(window[1]/100)):
					cv2.line(frame, (window[0]/2-10,window[1]-40-i*100),(window[0]/2+10,window[1]-40-i*100),(0,0,0),1)

				cv_x, cv_z = mapping(x,z,window)
				cv_tl = (cv_x-10,cv_z-10)
				cv_br = (cv_x+10,cv_z+10)
				for k in range(len(self.tracker.tracks[j].trace)):
					x_k = self.tracker.tracks[j].trace_state[k][0,0]
					z_k = self.tracker.tracks[j].trace_state[k][0,2]
					cv_x_k, cv_z_k = mapping(x_k, z_k, window)	

					cv2.circle(frame,(cv_x_k,cv_z_k), 3, track_colors[j],-1)
				cv2.rectangle(frame,cv_tl,cv_br,track_colors[j],1)
				cv2.putText(frame,str(self.tracker.tracks[j].trackId), (cv_x-10,cv_z-20),0, 0.5, track_colors[j],2)
				cv2.circle(frame,(cv_x,cv_z), 3, (0,0,0),-1)
				'''

				msg = ObjTracking()
				msg.object_id = self.tracker.tracks[j].trackId
				msg.pos.x = current[2]
				msg.pos.y = -current[0]
				msg.pos.z = current[1]
				msg.vel.x = velocity[2]
				msg.vel.y = -velocity[0]
				msg.vel.z = velocity[1]
				objects.objects.append(msg)

		cv2.imshow('image',frame)
		self._pub.publish(objects)
			
		if cv2.waitKey(1) & 0xFF == ord('q'):
			cv2.destroyAllWindows()
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	

def main(args=None):
    rclpy.init()
    node = MotNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()