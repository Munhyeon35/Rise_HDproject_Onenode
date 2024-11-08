// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from yolov8_msgs:msg/SegmentCenters.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "yolov8_msgs/msg/detail/segment_centers__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace yolov8_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void SegmentCenters_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) yolov8_msgs::msg::SegmentCenters(_init);
}

void SegmentCenters_fini_function(void * message_memory)
{
  auto typed_message = static_cast<yolov8_msgs::msg::SegmentCenters *>(message_memory);
  typed_message->~SegmentCenters();
}

size_t size_function__SegmentCenters__id(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int16_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SegmentCenters__id(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int16_t> *>(untyped_member);
  return &member[index];
}

void * get_function__SegmentCenters__id(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int16_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__SegmentCenters__id(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int16_t *>(
    get_const_function__SegmentCenters__id(untyped_member, index));
  auto & value = *reinterpret_cast<int16_t *>(untyped_value);
  value = item;
}

void assign_function__SegmentCenters__id(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int16_t *>(
    get_function__SegmentCenters__id(untyped_member, index));
  const auto & value = *reinterpret_cast<const int16_t *>(untyped_value);
  item = value;
}

void resize_function__SegmentCenters__id(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int16_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__SegmentCenters__pixel_x(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int16_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SegmentCenters__pixel_x(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int16_t> *>(untyped_member);
  return &member[index];
}

void * get_function__SegmentCenters__pixel_x(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int16_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__SegmentCenters__pixel_x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int16_t *>(
    get_const_function__SegmentCenters__pixel_x(untyped_member, index));
  auto & value = *reinterpret_cast<int16_t *>(untyped_value);
  value = item;
}

void assign_function__SegmentCenters__pixel_x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int16_t *>(
    get_function__SegmentCenters__pixel_x(untyped_member, index));
  const auto & value = *reinterpret_cast<const int16_t *>(untyped_value);
  item = value;
}

void resize_function__SegmentCenters__pixel_x(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int16_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__SegmentCenters__pixel_y(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<int16_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SegmentCenters__pixel_y(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<int16_t> *>(untyped_member);
  return &member[index];
}

void * get_function__SegmentCenters__pixel_y(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<int16_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__SegmentCenters__pixel_y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const int16_t *>(
    get_const_function__SegmentCenters__pixel_y(untyped_member, index));
  auto & value = *reinterpret_cast<int16_t *>(untyped_value);
  value = item;
}

void assign_function__SegmentCenters__pixel_y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<int16_t *>(
    get_function__SegmentCenters__pixel_y(untyped_member, index));
  const auto & value = *reinterpret_cast<const int16_t *>(untyped_value);
  item = value;
}

void resize_function__SegmentCenters__pixel_y(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<int16_t> *>(untyped_member);
  member->resize(size);
}

size_t size_function__SegmentCenters__x(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SegmentCenters__x(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__SegmentCenters__x(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__SegmentCenters__x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__SegmentCenters__x(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__SegmentCenters__x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__SegmentCenters__x(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__SegmentCenters__x(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__SegmentCenters__y(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SegmentCenters__y(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__SegmentCenters__y(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__SegmentCenters__y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__SegmentCenters__y(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__SegmentCenters__y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__SegmentCenters__y(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__SegmentCenters__y(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__SegmentCenters__z(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SegmentCenters__z(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__SegmentCenters__z(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__SegmentCenters__z(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__SegmentCenters__z(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__SegmentCenters__z(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__SegmentCenters__z(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__SegmentCenters__z(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__SegmentCenters__secs(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SegmentCenters__secs(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__SegmentCenters__secs(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__SegmentCenters__secs(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__SegmentCenters__secs(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__SegmentCenters__secs(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__SegmentCenters__secs(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__SegmentCenters__secs(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SegmentCenters_message_member_array[8] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolov8_msgs::msg::SegmentCenters, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolov8_msgs::msg::SegmentCenters, id),  // bytes offset in struct
    nullptr,  // default value
    size_function__SegmentCenters__id,  // size() function pointer
    get_const_function__SegmentCenters__id,  // get_const(index) function pointer
    get_function__SegmentCenters__id,  // get(index) function pointer
    fetch_function__SegmentCenters__id,  // fetch(index, &value) function pointer
    assign_function__SegmentCenters__id,  // assign(index, value) function pointer
    resize_function__SegmentCenters__id  // resize(index) function pointer
  },
  {
    "pixel_x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolov8_msgs::msg::SegmentCenters, pixel_x),  // bytes offset in struct
    nullptr,  // default value
    size_function__SegmentCenters__pixel_x,  // size() function pointer
    get_const_function__SegmentCenters__pixel_x,  // get_const(index) function pointer
    get_function__SegmentCenters__pixel_x,  // get(index) function pointer
    fetch_function__SegmentCenters__pixel_x,  // fetch(index, &value) function pointer
    assign_function__SegmentCenters__pixel_x,  // assign(index, value) function pointer
    resize_function__SegmentCenters__pixel_x  // resize(index) function pointer
  },
  {
    "pixel_y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolov8_msgs::msg::SegmentCenters, pixel_y),  // bytes offset in struct
    nullptr,  // default value
    size_function__SegmentCenters__pixel_y,  // size() function pointer
    get_const_function__SegmentCenters__pixel_y,  // get_const(index) function pointer
    get_function__SegmentCenters__pixel_y,  // get(index) function pointer
    fetch_function__SegmentCenters__pixel_y,  // fetch(index, &value) function pointer
    assign_function__SegmentCenters__pixel_y,  // assign(index, value) function pointer
    resize_function__SegmentCenters__pixel_y  // resize(index) function pointer
  },
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolov8_msgs::msg::SegmentCenters, x),  // bytes offset in struct
    nullptr,  // default value
    size_function__SegmentCenters__x,  // size() function pointer
    get_const_function__SegmentCenters__x,  // get_const(index) function pointer
    get_function__SegmentCenters__x,  // get(index) function pointer
    fetch_function__SegmentCenters__x,  // fetch(index, &value) function pointer
    assign_function__SegmentCenters__x,  // assign(index, value) function pointer
    resize_function__SegmentCenters__x  // resize(index) function pointer
  },
  {
    "y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolov8_msgs::msg::SegmentCenters, y),  // bytes offset in struct
    nullptr,  // default value
    size_function__SegmentCenters__y,  // size() function pointer
    get_const_function__SegmentCenters__y,  // get_const(index) function pointer
    get_function__SegmentCenters__y,  // get(index) function pointer
    fetch_function__SegmentCenters__y,  // fetch(index, &value) function pointer
    assign_function__SegmentCenters__y,  // assign(index, value) function pointer
    resize_function__SegmentCenters__y  // resize(index) function pointer
  },
  {
    "z",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolov8_msgs::msg::SegmentCenters, z),  // bytes offset in struct
    nullptr,  // default value
    size_function__SegmentCenters__z,  // size() function pointer
    get_const_function__SegmentCenters__z,  // get_const(index) function pointer
    get_function__SegmentCenters__z,  // get(index) function pointer
    fetch_function__SegmentCenters__z,  // fetch(index, &value) function pointer
    assign_function__SegmentCenters__z,  // assign(index, value) function pointer
    resize_function__SegmentCenters__z  // resize(index) function pointer
  },
  {
    "secs",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolov8_msgs::msg::SegmentCenters, secs),  // bytes offset in struct
    nullptr,  // default value
    size_function__SegmentCenters__secs,  // size() function pointer
    get_const_function__SegmentCenters__secs,  // get_const(index) function pointer
    get_function__SegmentCenters__secs,  // get(index) function pointer
    fetch_function__SegmentCenters__secs,  // fetch(index, &value) function pointer
    assign_function__SegmentCenters__secs,  // assign(index, value) function pointer
    resize_function__SegmentCenters__secs  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SegmentCenters_message_members = {
  "yolov8_msgs::msg",  // message namespace
  "SegmentCenters",  // message name
  8,  // number of fields
  sizeof(yolov8_msgs::msg::SegmentCenters),
  SegmentCenters_message_member_array,  // message members
  SegmentCenters_init_function,  // function to initialize message memory (memory has to be allocated)
  SegmentCenters_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SegmentCenters_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SegmentCenters_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace yolov8_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<yolov8_msgs::msg::SegmentCenters>()
{
  return &::yolov8_msgs::msg::rosidl_typesupport_introspection_cpp::SegmentCenters_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, yolov8_msgs, msg, SegmentCenters)() {
  return &::yolov8_msgs::msg::rosidl_typesupport_introspection_cpp::SegmentCenters_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
