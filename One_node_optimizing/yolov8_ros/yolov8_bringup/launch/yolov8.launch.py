# Copyright (C) 2023  Miguel Ángel González Santamarta

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.


from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument


def generate_launch_description():

    #
    # ARGS
    #
    model_cmd = DeclareLaunchArgument("model", default_value="yolo11n-seg.pt")

    device_cmd = DeclareLaunchArgument("device", default_value="cpu")

    enable_cmd = DeclareLaunchArgument("enable", default_value="True")

    threshold_cmd = DeclareLaunchArgument("threshold", default_value="0.5")

    input_image_topic_cmd = DeclareLaunchArgument("input_image_topic", default_value="/camera_03/color/image_raw")

    input_depth_topic_cmd = DeclareLaunchArgument(
        "input_depth_topic",
        default_value="/camera_03/depth/image_raw",
        description="Name of the input depth topic")
    
    input_depth_info_topic_cmd = DeclareLaunchArgument(
        "input_depth_info_topic",
        default_value="/camera_03/depth/camera_info",
        description="Name of the input depth info topic")
    

    image_reliability_cmd = DeclareLaunchArgument("image_reliability", default_value="2", choices=["0", "1", "2"],
        description="Specific reliability QoS of the input image topic (0=system default, 1=Reliable, 2=Best Effort)")

    namespace_cmd = DeclareLaunchArgument("namespace", default_value="yolo")

    target_frame_cmd = DeclareLaunchArgument(
        "target_frame",
        default_value="camera_03_link",              ##  camera_02_link   / odom   // camera_link [astra pro plus]
        description="Target frame to transform the 3D boxes")
    
    model = LaunchConfiguration("model")
    device = LaunchConfiguration("device")
    enable = LaunchConfiguration("enable")
    threshold = LaunchConfiguration("threshold")
    input_image_topic = LaunchConfiguration("input_image_topic")
    image_reliability = LaunchConfiguration("image_reliability")
    namespace = LaunchConfiguration("namespace")
    input_depth_info_topic = LaunchConfiguration("input_depth_info_topic")
    input_depth_topic = LaunchConfiguration("input_depth_topic")
    target_frame = LaunchConfiguration("target_frame")

    # tracker = LaunchConfiguration("tracker")
    # tracker_cmd = DeclareLaunchArgument(
    #     "tracker",
    #     default_value="bytetrack.yaml",
    #     description="Tracker name or path")


    #
    # NODES
    #
    detector_node_cmd = Node(
        package="yolov8_ros",
        executable="yolov8_node",
        name="yolov8_node",
        namespace=namespace,
        parameters=[{
            "model": model,
            "device": device,
            "enable": enable,
            "threshold": threshold,
            "image_reliability": image_reliability,
            "topic_name": input_image_topic,
        }],
        remappings=[
            ("depth_image", input_depth_topic),
            ("depth_info", input_depth_info_topic),
        ]
    )
    
    mot_node_cmd = Node(
        package="yolov8_ros",
        executable="object_track_ROS",
        name="mot_node",
        namespace=namespace,
        parameters=[{"camera_link": target_frame}]
    )

    time_graph_cmd = Node(
        package="yolov8_ros",
        executable="time_graph",
        name="time_graph_node",
        namespace=namespace,
        remappings=[("image_raw", input_image_topic),
                    ("depth_image", input_depth_topic),
                    ("mot_objects", "/yolo/mot_objects")
                    ]
    )

    # debug_node_cmd = Node(
    #     package="yolov8_ros",
    #     executable="debug_node",
    #     name="debug_node",
    #     namespace=namespace,
    #     parameters=[{"image_reliability": image_reliability}],
    #     remappings=[
    #         ("image_raw", input_image_topic),
    #         ("detections", "tracking")
    #     ]
    # )

    ld = LaunchDescription()

    ld.add_action(model_cmd)
    ld.add_action(device_cmd)
    ld.add_action(enable_cmd)
    ld.add_action(threshold_cmd)
    ld.add_action(input_image_topic_cmd)
    ld.add_action(image_reliability_cmd)
    ld.add_action(namespace_cmd)
    ld.add_action(input_depth_topic_cmd)
    ld.add_action(input_depth_info_topic_cmd)
    ld.add_action(target_frame_cmd)
    ld.add_action(detector_node_cmd)
    ld.add_action(mot_node_cmd)
    ld.add_action(time_graph_cmd)
    
    
    # ld.add_action(debug_node_cmd)

    return ld
