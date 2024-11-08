// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from yolov8_msgs:msg/SegmentCenters.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__SEGMENT_CENTERS__BUILDER_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__SEGMENT_CENTERS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "yolov8_msgs/msg/detail/segment_centers__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace yolov8_msgs
{

namespace msg
{

namespace builder
{

class Init_SegmentCenters_secs
{
public:
  explicit Init_SegmentCenters_secs(::yolov8_msgs::msg::SegmentCenters & msg)
  : msg_(msg)
  {}
  ::yolov8_msgs::msg::SegmentCenters secs(::yolov8_msgs::msg::SegmentCenters::_secs_type arg)
  {
    msg_.secs = std::move(arg);
    return std::move(msg_);
  }

private:
  ::yolov8_msgs::msg::SegmentCenters msg_;
};

class Init_SegmentCenters_z
{
public:
  explicit Init_SegmentCenters_z(::yolov8_msgs::msg::SegmentCenters & msg)
  : msg_(msg)
  {}
  Init_SegmentCenters_secs z(::yolov8_msgs::msg::SegmentCenters::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_SegmentCenters_secs(msg_);
  }

private:
  ::yolov8_msgs::msg::SegmentCenters msg_;
};

class Init_SegmentCenters_y
{
public:
  explicit Init_SegmentCenters_y(::yolov8_msgs::msg::SegmentCenters & msg)
  : msg_(msg)
  {}
  Init_SegmentCenters_z y(::yolov8_msgs::msg::SegmentCenters::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_SegmentCenters_z(msg_);
  }

private:
  ::yolov8_msgs::msg::SegmentCenters msg_;
};

class Init_SegmentCenters_x
{
public:
  explicit Init_SegmentCenters_x(::yolov8_msgs::msg::SegmentCenters & msg)
  : msg_(msg)
  {}
  Init_SegmentCenters_y x(::yolov8_msgs::msg::SegmentCenters::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_SegmentCenters_y(msg_);
  }

private:
  ::yolov8_msgs::msg::SegmentCenters msg_;
};

class Init_SegmentCenters_pixel_y
{
public:
  explicit Init_SegmentCenters_pixel_y(::yolov8_msgs::msg::SegmentCenters & msg)
  : msg_(msg)
  {}
  Init_SegmentCenters_x pixel_y(::yolov8_msgs::msg::SegmentCenters::_pixel_y_type arg)
  {
    msg_.pixel_y = std::move(arg);
    return Init_SegmentCenters_x(msg_);
  }

private:
  ::yolov8_msgs::msg::SegmentCenters msg_;
};

class Init_SegmentCenters_pixel_x
{
public:
  explicit Init_SegmentCenters_pixel_x(::yolov8_msgs::msg::SegmentCenters & msg)
  : msg_(msg)
  {}
  Init_SegmentCenters_pixel_y pixel_x(::yolov8_msgs::msg::SegmentCenters::_pixel_x_type arg)
  {
    msg_.pixel_x = std::move(arg);
    return Init_SegmentCenters_pixel_y(msg_);
  }

private:
  ::yolov8_msgs::msg::SegmentCenters msg_;
};

class Init_SegmentCenters_id
{
public:
  explicit Init_SegmentCenters_id(::yolov8_msgs::msg::SegmentCenters & msg)
  : msg_(msg)
  {}
  Init_SegmentCenters_pixel_x id(::yolov8_msgs::msg::SegmentCenters::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_SegmentCenters_pixel_x(msg_);
  }

private:
  ::yolov8_msgs::msg::SegmentCenters msg_;
};

class Init_SegmentCenters_header
{
public:
  Init_SegmentCenters_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SegmentCenters_id header(::yolov8_msgs::msg::SegmentCenters::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_SegmentCenters_id(msg_);
  }

private:
  ::yolov8_msgs::msg::SegmentCenters msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::yolov8_msgs::msg::SegmentCenters>()
{
  return yolov8_msgs::msg::builder::Init_SegmentCenters_header();
}

}  // namespace yolov8_msgs

#endif  // YOLOV8_MSGS__MSG__DETAIL__SEGMENT_CENTERS__BUILDER_HPP_
