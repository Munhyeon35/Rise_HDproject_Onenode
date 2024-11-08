// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from yolov8_msgs:msg/ObjTracking.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__OBJ_TRACKING__STRUCT_H_
#define YOLOV8_MSGS__MSG__DETAIL__OBJ_TRACKING__STRUCT_H_

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
// Member 'pos'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'vel'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/ObjTracking in the package yolov8_msgs.
typedef struct yolov8_msgs__msg__ObjTracking
{
  std_msgs__msg__Header header;
  int16_t object_id;
  /// Central point
  geometry_msgs__msg__Point pos;
  /// Linear velocity
  geometry_msgs__msg__Vector3 vel;
} yolov8_msgs__msg__ObjTracking;

// Struct for a sequence of yolov8_msgs__msg__ObjTracking.
typedef struct yolov8_msgs__msg__ObjTracking__Sequence
{
  yolov8_msgs__msg__ObjTracking * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} yolov8_msgs__msg__ObjTracking__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // YOLOV8_MSGS__MSG__DETAIL__OBJ_TRACKING__STRUCT_H_
