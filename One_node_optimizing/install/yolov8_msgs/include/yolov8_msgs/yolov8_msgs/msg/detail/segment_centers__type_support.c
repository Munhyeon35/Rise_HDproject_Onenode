// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from yolov8_msgs:msg/SegmentCenters.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "yolov8_msgs/msg/detail/segment_centers__rosidl_typesupport_introspection_c.h"
#include "yolov8_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "yolov8_msgs/msg/detail/segment_centers__functions.h"
#include "yolov8_msgs/msg/detail/segment_centers__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `id`
// Member `pixel_x`
// Member `pixel_y`
// Member `x`
// Member `y`
// Member `z`
// Member `secs`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__SegmentCenters_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  yolov8_msgs__msg__SegmentCenters__init(message_memory);
}

void yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__SegmentCenters_fini_function(void * message_memory)
{
  yolov8_msgs__msg__SegmentCenters__fini(message_memory);
}

size_t yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__size_function__SegmentCenters__id(
  const void * untyped_member)
{
  const rosidl_runtime_c__int16__Sequence * member =
    (const rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return member->size;
}

const void * yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_const_function__SegmentCenters__id(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int16__Sequence * member =
    (const rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_function__SegmentCenters__id(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int16__Sequence * member =
    (rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return &member->data[index];
}

void yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__fetch_function__SegmentCenters__id(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int16_t * item =
    ((const int16_t *)
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_const_function__SegmentCenters__id(untyped_member, index));
  int16_t * value =
    (int16_t *)(untyped_value);
  *value = *item;
}

void yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__assign_function__SegmentCenters__id(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int16_t * item =
    ((int16_t *)
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_function__SegmentCenters__id(untyped_member, index));
  const int16_t * value =
    (const int16_t *)(untyped_value);
  *item = *value;
}

bool yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__resize_function__SegmentCenters__id(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int16__Sequence * member =
    (rosidl_runtime_c__int16__Sequence *)(untyped_member);
  rosidl_runtime_c__int16__Sequence__fini(member);
  return rosidl_runtime_c__int16__Sequence__init(member, size);
}

size_t yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__size_function__SegmentCenters__pixel_x(
  const void * untyped_member)
{
  const rosidl_runtime_c__int16__Sequence * member =
    (const rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return member->size;
}

const void * yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_const_function__SegmentCenters__pixel_x(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int16__Sequence * member =
    (const rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_function__SegmentCenters__pixel_x(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int16__Sequence * member =
    (rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return &member->data[index];
}

void yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__fetch_function__SegmentCenters__pixel_x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int16_t * item =
    ((const int16_t *)
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_const_function__SegmentCenters__pixel_x(untyped_member, index));
  int16_t * value =
    (int16_t *)(untyped_value);
  *value = *item;
}

void yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__assign_function__SegmentCenters__pixel_x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int16_t * item =
    ((int16_t *)
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_function__SegmentCenters__pixel_x(untyped_member, index));
  const int16_t * value =
    (const int16_t *)(untyped_value);
  *item = *value;
}

bool yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__resize_function__SegmentCenters__pixel_x(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int16__Sequence * member =
    (rosidl_runtime_c__int16__Sequence *)(untyped_member);
  rosidl_runtime_c__int16__Sequence__fini(member);
  return rosidl_runtime_c__int16__Sequence__init(member, size);
}

size_t yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__size_function__SegmentCenters__pixel_y(
  const void * untyped_member)
{
  const rosidl_runtime_c__int16__Sequence * member =
    (const rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return member->size;
}

const void * yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_const_function__SegmentCenters__pixel_y(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int16__Sequence * member =
    (const rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_function__SegmentCenters__pixel_y(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int16__Sequence * member =
    (rosidl_runtime_c__int16__Sequence *)(untyped_member);
  return &member->data[index];
}

void yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__fetch_function__SegmentCenters__pixel_y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int16_t * item =
    ((const int16_t *)
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_const_function__SegmentCenters__pixel_y(untyped_member, index));
  int16_t * value =
    (int16_t *)(untyped_value);
  *value = *item;
}

void yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__assign_function__SegmentCenters__pixel_y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int16_t * item =
    ((int16_t *)
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_function__SegmentCenters__pixel_y(untyped_member, index));
  const int16_t * value =
    (const int16_t *)(untyped_value);
  *item = *value;
}

bool yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__resize_function__SegmentCenters__pixel_y(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int16__Sequence * member =
    (rosidl_runtime_c__int16__Sequence *)(untyped_member);
  rosidl_runtime_c__int16__Sequence__fini(member);
  return rosidl_runtime_c__int16__Sequence__init(member, size);
}

size_t yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__size_function__SegmentCenters__x(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_const_function__SegmentCenters__x(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_function__SegmentCenters__x(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__fetch_function__SegmentCenters__x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_const_function__SegmentCenters__x(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__assign_function__SegmentCenters__x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_function__SegmentCenters__x(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__resize_function__SegmentCenters__x(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__size_function__SegmentCenters__y(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_const_function__SegmentCenters__y(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_function__SegmentCenters__y(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__fetch_function__SegmentCenters__y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_const_function__SegmentCenters__y(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__assign_function__SegmentCenters__y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_function__SegmentCenters__y(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__resize_function__SegmentCenters__y(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__size_function__SegmentCenters__z(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_const_function__SegmentCenters__z(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_function__SegmentCenters__z(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__fetch_function__SegmentCenters__z(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_const_function__SegmentCenters__z(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__assign_function__SegmentCenters__z(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_function__SegmentCenters__z(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__resize_function__SegmentCenters__z(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__size_function__SegmentCenters__secs(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_const_function__SegmentCenters__secs(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_function__SegmentCenters__secs(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__fetch_function__SegmentCenters__secs(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_const_function__SegmentCenters__secs(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__assign_function__SegmentCenters__secs(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_function__SegmentCenters__secs(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__resize_function__SegmentCenters__secs(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__SegmentCenters_message_member_array[8] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolov8_msgs__msg__SegmentCenters, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolov8_msgs__msg__SegmentCenters, id),  // bytes offset in struct
    NULL,  // default value
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__size_function__SegmentCenters__id,  // size() function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_const_function__SegmentCenters__id,  // get_const(index) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_function__SegmentCenters__id,  // get(index) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__fetch_function__SegmentCenters__id,  // fetch(index, &value) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__assign_function__SegmentCenters__id,  // assign(index, value) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__resize_function__SegmentCenters__id  // resize(index) function pointer
  },
  {
    "pixel_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolov8_msgs__msg__SegmentCenters, pixel_x),  // bytes offset in struct
    NULL,  // default value
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__size_function__SegmentCenters__pixel_x,  // size() function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_const_function__SegmentCenters__pixel_x,  // get_const(index) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_function__SegmentCenters__pixel_x,  // get(index) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__fetch_function__SegmentCenters__pixel_x,  // fetch(index, &value) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__assign_function__SegmentCenters__pixel_x,  // assign(index, value) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__resize_function__SegmentCenters__pixel_x  // resize(index) function pointer
  },
  {
    "pixel_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolov8_msgs__msg__SegmentCenters, pixel_y),  // bytes offset in struct
    NULL,  // default value
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__size_function__SegmentCenters__pixel_y,  // size() function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_const_function__SegmentCenters__pixel_y,  // get_const(index) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_function__SegmentCenters__pixel_y,  // get(index) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__fetch_function__SegmentCenters__pixel_y,  // fetch(index, &value) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__assign_function__SegmentCenters__pixel_y,  // assign(index, value) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__resize_function__SegmentCenters__pixel_y  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolov8_msgs__msg__SegmentCenters, x),  // bytes offset in struct
    NULL,  // default value
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__size_function__SegmentCenters__x,  // size() function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_const_function__SegmentCenters__x,  // get_const(index) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_function__SegmentCenters__x,  // get(index) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__fetch_function__SegmentCenters__x,  // fetch(index, &value) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__assign_function__SegmentCenters__x,  // assign(index, value) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__resize_function__SegmentCenters__x  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolov8_msgs__msg__SegmentCenters, y),  // bytes offset in struct
    NULL,  // default value
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__size_function__SegmentCenters__y,  // size() function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_const_function__SegmentCenters__y,  // get_const(index) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_function__SegmentCenters__y,  // get(index) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__fetch_function__SegmentCenters__y,  // fetch(index, &value) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__assign_function__SegmentCenters__y,  // assign(index, value) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__resize_function__SegmentCenters__y  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolov8_msgs__msg__SegmentCenters, z),  // bytes offset in struct
    NULL,  // default value
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__size_function__SegmentCenters__z,  // size() function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_const_function__SegmentCenters__z,  // get_const(index) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_function__SegmentCenters__z,  // get(index) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__fetch_function__SegmentCenters__z,  // fetch(index, &value) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__assign_function__SegmentCenters__z,  // assign(index, value) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__resize_function__SegmentCenters__z  // resize(index) function pointer
  },
  {
    "secs",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(yolov8_msgs__msg__SegmentCenters, secs),  // bytes offset in struct
    NULL,  // default value
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__size_function__SegmentCenters__secs,  // size() function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_const_function__SegmentCenters__secs,  // get_const(index) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__get_function__SegmentCenters__secs,  // get(index) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__fetch_function__SegmentCenters__secs,  // fetch(index, &value) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__assign_function__SegmentCenters__secs,  // assign(index, value) function pointer
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__resize_function__SegmentCenters__secs  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__SegmentCenters_message_members = {
  "yolov8_msgs__msg",  // message namespace
  "SegmentCenters",  // message name
  8,  // number of fields
  sizeof(yolov8_msgs__msg__SegmentCenters),
  yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__SegmentCenters_message_member_array,  // message members
  yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__SegmentCenters_init_function,  // function to initialize message memory (memory has to be allocated)
  yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__SegmentCenters_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__SegmentCenters_message_type_support_handle = {
  0,
  &yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__SegmentCenters_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_yolov8_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, yolov8_msgs, msg, SegmentCenters)() {
  yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__SegmentCenters_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__SegmentCenters_message_type_support_handle.typesupport_identifier) {
    yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__SegmentCenters_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &yolov8_msgs__msg__SegmentCenters__rosidl_typesupport_introspection_c__SegmentCenters_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
