// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from yolov8_msgs:msg/ObjTracking.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__OBJ_TRACKING__TRAITS_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__OBJ_TRACKING__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "yolov8_msgs/msg/detail/obj_tracking__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'pos'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'vel'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace yolov8_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ObjTracking & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: object_id
  {
    out << "object_id: ";
    rosidl_generator_traits::value_to_yaml(msg.object_id, out);
    out << ", ";
  }

  // member: pos
  {
    out << "pos: ";
    to_flow_style_yaml(msg.pos, out);
    out << ", ";
  }

  // member: vel
  {
    out << "vel: ";
    to_flow_style_yaml(msg.vel, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ObjTracking & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: object_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "object_id: ";
    rosidl_generator_traits::value_to_yaml(msg.object_id, out);
    out << "\n";
  }

  // member: pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos:\n";
    to_block_style_yaml(msg.pos, out, indentation + 2);
  }

  // member: vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel:\n";
    to_block_style_yaml(msg.vel, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ObjTracking & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace yolov8_msgs

namespace rosidl_generator_traits
{

[[deprecated("use yolov8_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const yolov8_msgs::msg::ObjTracking & msg,
  std::ostream & out, size_t indentation = 0)
{
  yolov8_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use yolov8_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const yolov8_msgs::msg::ObjTracking & msg)
{
  return yolov8_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<yolov8_msgs::msg::ObjTracking>()
{
  return "yolov8_msgs::msg::ObjTracking";
}

template<>
inline const char * name<yolov8_msgs::msg::ObjTracking>()
{
  return "yolov8_msgs/msg/ObjTracking";
}

template<>
struct has_fixed_size<yolov8_msgs::msg::ObjTracking>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<geometry_msgs::msg::Vector3>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<yolov8_msgs::msg::ObjTracking>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<geometry_msgs::msg::Vector3>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<yolov8_msgs::msg::ObjTracking>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // YOLOV8_MSGS__MSG__DETAIL__OBJ_TRACKING__TRAITS_HPP_
