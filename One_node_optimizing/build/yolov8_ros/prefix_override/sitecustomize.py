import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/hrc/HD-Robotic_camera/One_node_optimizing/install/yolov8_ros'
