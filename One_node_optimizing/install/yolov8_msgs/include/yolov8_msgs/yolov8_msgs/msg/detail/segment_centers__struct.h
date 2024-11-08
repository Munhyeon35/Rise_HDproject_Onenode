// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yolov8_msgs:msg/SegmentCenters.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__SEGMENT_CENTERS__STRUCT_H_
#define YOLOV8_MSGS__MSG__DETAIL__SEGMENT_CENTERS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'id'
// Member 'pixel_x'
// Member 'pixel_y'
// Member 'x'
// Member 'y'
// Member 'z'
// Member 'secs'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/SegmentCenters in the package yolov8_msgs.
typedef struct yolov8_msgs__msg__SegmentCenters
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__int16__Sequence id;
  rosidl_runtime_c__int16__Sequence pixel_x;
  rosidl_runtime_c__int16__Sequence pixel_y;
  rosidl_runtime_c__double__Sequence x;
  rosidl_runtime_c__double__Sequence y;
  rosidl_runtime_c__double__Sequence z;
  rosidl_runtime_c__double__Sequence secs;
} yolov8_msgs__msg__SegmentCenters;

// Struct for a sequence of yolov8_msgs__msg__SegmentCenters.
typedef struct yolov8_msgs__msg__SegmentCenters__Sequence
{
  yolov8_msgs__msg__SegmentCenters * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yolov8_msgs__msg__SegmentCenters__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YOLOV8_MSGS__MSG__DETAIL__SEGMENT_CENTERS__STRUCT_H_
