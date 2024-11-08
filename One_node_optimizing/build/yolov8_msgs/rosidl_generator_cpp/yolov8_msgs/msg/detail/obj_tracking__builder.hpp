// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yolov8_msgs:msg/ObjTracking.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__OBJ_TRACKING__BUILDER_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__OBJ_TRACKING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "yolov8_msgs/msg/detail/obj_tracking__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace yolov8_msgs
{

namespace msg
{

namespace builder
{

class Init_ObjTracking_vel
{
public:
  explicit Init_ObjTracking_vel(::yolov8_msgs::msg::ObjTracking & msg)
  : msg_(msg)
  {}
  ::yolov8_msgs::msg::ObjTracking vel(::yolov8_msgs::msg::ObjTracking::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yolov8_msgs::msg::ObjTracking msg_;
};

class Init_ObjTracking_pos
{
public:
  explicit Init_ObjTracking_pos(::yolov8_msgs::msg::ObjTracking & msg)
  : msg_(msg)
  {}
  Init_ObjTracking_vel pos(::yolov8_msgs::msg::ObjTracking::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_ObjTracking_vel(msg_);
  }

private:
  ::yolov8_msgs::msg::ObjTracking msg_;
};

class Init_ObjTracking_object_id
{
public:
  explicit Init_ObjTracking_object_id(::yolov8_msgs::msg::ObjTracking & msg)
  : msg_(msg)
  {}
  Init_ObjTracking_pos object_id(::yolov8_msgs::msg::ObjTracking::_object_id_type arg)
  {
    msg_.object_id = std::move(arg);
    return Init_ObjTracking_pos(msg_);
  }

private:
  ::yolov8_msgs::msg::ObjTracking msg_;
};

class Init_ObjTracking_header
{
public:
  Init_ObjTracking_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObjTracking_object_id header(::yolov8_msgs::msg::ObjTracking::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ObjTracking_object_id(msg_);
  }

private:
  ::yolov8_msgs::msg::ObjTracking msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yolov8_msgs::msg::ObjTracking>()
{
  return yolov8_msgs::msg::builder::Init_ObjTracking_header();
}

}  // namespace yolov8_msgs

#endif  // YOLOV8_MSGS__MSG__DETAIL__OBJ_TRACKING__BUILDER_HPP_
