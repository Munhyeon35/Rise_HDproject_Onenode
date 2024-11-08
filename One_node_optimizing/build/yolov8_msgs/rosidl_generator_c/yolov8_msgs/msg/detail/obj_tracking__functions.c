// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from yolov8_msgs:msg/ObjTracking.idl
// generated code does not contain a copyright notice
#include "yolov8_msgs/msg/detail/obj_tracking__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `pos`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `vel`
#include "geometry_msgs/msg/detail/vector3__functions.h"

bool
yolov8_msgs__msg__ObjTracking__init(yolov8_msgs__msg__ObjTracking * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    yolov8_msgs__msg__ObjTracking__fini(msg);
    return false;
  }
  // object_id
  // pos
  if (!geometry_msgs__msg__Point__init(&msg->pos)) {
    yolov8_msgs__msg__ObjTracking__fini(msg);
    return false;
  }
  // vel
  if (!geometry_msgs__msg__Vector3__init(&msg->vel)) {
    yolov8_msgs__msg__ObjTracking__fini(msg);
    return false;
  }
  return true;
}

void
yolov8_msgs__msg__ObjTracking__fini(yolov8_msgs__msg__ObjTracking * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // object_id
  // pos
  geometry_msgs__msg__Point__fini(&msg->pos);
  // vel
  geometry_msgs__msg__Vector3__fini(&msg->vel);
}

bool
yolov8_msgs__msg__ObjTracking__are_equal(const yolov8_msgs__msg__ObjTracking * lhs, const yolov8_msgs__msg__ObjTracking * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // object_id
  if (lhs->object_id != rhs->object_id) {
    return false;
  }
  // pos
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->pos), &(rhs->pos)))
  {
    return false;
  }
  // vel
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->vel), &(rhs->vel)))
  {
    return false;
  }
  return true;
}

bool
yolov8_msgs__msg__ObjTracking__copy(
  const yolov8_msgs__msg__ObjTracking * input,
  yolov8_msgs__msg__ObjTracking * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // object_id
  output->object_id = input->object_id;
  // pos
  if (!geometry_msgs__msg__Point__copy(
      &(input->pos), &(output->pos)))
  {
    return false;
  }
  // vel
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->vel), &(output->vel)))
  {
    return false;
  }
  return true;
}

yolov8_msgs__msg__ObjTracking *
yolov8_msgs__msg__ObjTracking__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolov8_msgs__msg__ObjTracking * msg = (yolov8_msgs__msg__ObjTracking *)allocator.allocate(sizeof(yolov8_msgs__msg__ObjTracking), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(yolov8_msgs__msg__ObjTracking));
  bool success = yolov8_msgs__msg__ObjTracking__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
yolov8_msgs__msg__ObjTracking__destroy(yolov8_msgs__msg__ObjTracking * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    yolov8_msgs__msg__ObjTracking__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
yolov8_msgs__msg__ObjTracking__Sequence__init(yolov8_msgs__msg__ObjTracking__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolov8_msgs__msg__ObjTracking * data = NULL;

  if (size) {
    data = (yolov8_msgs__msg__ObjTracking *)allocator.zero_allocate(size, sizeof(yolov8_msgs__msg__ObjTracking), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = yolov8_msgs__msg__ObjTracking__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        yolov8_msgs__msg__ObjTracking__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
yolov8_msgs__msg__ObjTracking__Sequence__fini(yolov8_msgs__msg__ObjTracking__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      yolov8_msgs__msg__ObjTracking__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

yolov8_msgs__msg__ObjTracking__Sequence *
yolov8_msgs__msg__ObjTracking__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolov8_msgs__msg__ObjTracking__Sequence * array = (yolov8_msgs__msg__ObjTracking__Sequence *)allocator.allocate(sizeof(yolov8_msgs__msg__ObjTracking__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = yolov8_msgs__msg__ObjTracking__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
yolov8_msgs__msg__ObjTracking__Sequence__destroy(yolov8_msgs__msg__ObjTracking__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    yolov8_msgs__msg__ObjTracking__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
yolov8_msgs__msg__ObjTracking__Sequence__are_equal(const yolov8_msgs__msg__ObjTracking__Sequence * lhs, const yolov8_msgs__msg__ObjTracking__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!yolov8_msgs__msg__ObjTracking__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
yolov8_msgs__msg__ObjTracking__Sequence__copy(
  const yolov8_msgs__msg__ObjTracking__Sequence * input,
  yolov8_msgs__msg__ObjTracking__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(yolov8_msgs__msg__ObjTracking);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    yolov8_msgs__msg__ObjTracking * data =
      (yolov8_msgs__msg__ObjTracking *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!yolov8_msgs__msg__ObjTracking__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          yolov8_msgs__msg__ObjTracking__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!yolov8_msgs__msg__ObjTracking__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
