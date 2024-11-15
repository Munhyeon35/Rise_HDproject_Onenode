// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yolov8_msgs:msg/Objects.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__OBJECTS__STRUCT_H_
#define YOLOV8_MSGS__MSG__DETAIL__OBJECTS__STRUCT_H_

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
// Member 'objects'
#include "yolov8_msgs/msg/detail/obj_tracking__struct.h"

/// Struct defined in msg/Objects in the package yolov8_msgs.
typedef struct yolov8_msgs__msg__Objects
{
  std_msgs__msg__Header header;
  yolov8_msgs__msg__ObjTracking__Sequence objects;
} yolov8_msgs__msg__Objects;

// Struct for a sequence of yolov8_msgs__msg__Objects.
typedef struct yolov8_msgs__msg__Objects__Sequence
{
  yolov8_msgs__msg__Objects * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yolov8_msgs__msg__Objects__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YOLOV8_MSGS__MSG__DETAIL__OBJECTS__STRUCT_H_
