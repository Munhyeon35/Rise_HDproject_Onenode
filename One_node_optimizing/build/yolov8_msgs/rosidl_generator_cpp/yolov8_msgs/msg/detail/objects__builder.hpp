// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yolov8_msgs:msg/Objects.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__OBJECTS__BUILDER_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__OBJECTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "yolov8_msgs/msg/detail/objects__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace yolov8_msgs
{

namespace msg
{

namespace builder
{

class Init_Objects_objects
{
public:
  explicit Init_Objects_objects(::yolov8_msgs::msg::Objects & msg)
  : msg_(msg)
  {}
  ::yolov8_msgs::msg::Objects objects(::yolov8_msgs::msg::Objects::_objects_type arg)
  {
    msg_.objects = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yolov8_msgs::msg::Objects msg_;
};

class Init_Objects_header
{
public:
  Init_Objects_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Objects_objects header(::yolov8_msgs::msg::Objects::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Objects_objects(msg_);
  }

private:
  ::yolov8_msgs::msg::Objects msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yolov8_msgs::msg::Objects>()
{
  return yolov8_msgs::msg::builder::Init_Objects_header();
}

}  // namespace yolov8_msgs

#endif  // YOLOV8_MSGS__MSG__DETAIL__OBJECTS__BUILDER_HPP_
