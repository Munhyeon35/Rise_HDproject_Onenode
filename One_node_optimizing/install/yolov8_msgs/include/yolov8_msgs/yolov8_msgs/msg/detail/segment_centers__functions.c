// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from yolov8_msgs:msg/SegmentCenters.idl
// generated code does not contain a copyright notice
#include "yolov8_msgs/msg/detail/segment_centers__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `id`
// Member `pixel_x`
// Member `pixel_y`
// Member `x`
// Member `y`
// Member `z`
// Member `secs`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
yolov8_msgs__msg__SegmentCenters__init(yolov8_msgs__msg__SegmentCenters * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    yolov8_msgs__msg__SegmentCenters__fini(msg);
    return false;
  }
  // id
  if (!rosidl_runtime_c__int16__Sequence__init(&msg->id, 0)) {
    yolov8_msgs__msg__SegmentCenters__fini(msg);
    return false;
  }
  // pixel_x
  if (!rosidl_runtime_c__int16__Sequence__init(&msg->pixel_x, 0)) {
    yolov8_msgs__msg__SegmentCenters__fini(msg);
    return false;
  }
  // pixel_y
  if (!rosidl_runtime_c__int16__Sequence__init(&msg->pixel_y, 0)) {
    yolov8_msgs__msg__SegmentCenters__fini(msg);
    return false;
  }
  // x
  if (!rosidl_runtime_c__double__Sequence__init(&msg->x, 0)) {
    yolov8_msgs__msg__SegmentCenters__fini(msg);
    return false;
  }
  // y
  if (!rosidl_runtime_c__double__Sequence__init(&msg->y, 0)) {
    yolov8_msgs__msg__SegmentCenters__fini(msg);
    return false;
  }
  // z
  if (!rosidl_runtime_c__double__Sequence__init(&msg->z, 0)) {
    yolov8_msgs__msg__SegmentCenters__fini(msg);
    return false;
  }
  // secs
  if (!rosidl_runtime_c__double__Sequence__init(&msg->secs, 0)) {
    yolov8_msgs__msg__SegmentCenters__fini(msg);
    return false;
  }
  return true;
}

void
yolov8_msgs__msg__SegmentCenters__fini(yolov8_msgs__msg__SegmentCenters * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // id
  rosidl_runtime_c__int16__Sequence__fini(&msg->id);
  // pixel_x
  rosidl_runtime_c__int16__Sequence__fini(&msg->pixel_x);
  // pixel_y
  rosidl_runtime_c__int16__Sequence__fini(&msg->pixel_y);
  // x
  rosidl_runtime_c__double__Sequence__fini(&msg->x);
  // y
  rosidl_runtime_c__double__Sequence__fini(&msg->y);
  // z
  rosidl_runtime_c__double__Sequence__fini(&msg->z);
  // secs
  rosidl_runtime_c__double__Sequence__fini(&msg->secs);
}

bool
yolov8_msgs__msg__SegmentCenters__are_equal(const yolov8_msgs__msg__SegmentCenters * lhs, const yolov8_msgs__msg__SegmentCenters * rhs)
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
  // id
  if (!rosidl_runtime_c__int16__Sequence__are_equal(
      &(lhs->id), &(rhs->id)))
  {
    return false;
  }
  // pixel_x
  if (!rosidl_runtime_c__int16__Sequence__are_equal(
      &(lhs->pixel_x), &(rhs->pixel_x)))
  {
    return false;
  }
  // pixel_y
  if (!rosidl_runtime_c__int16__Sequence__are_equal(
      &(lhs->pixel_y), &(rhs->pixel_y)))
  {
    return false;
  }
  // x
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->x), &(rhs->x)))
  {
    return false;
  }
  // y
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->y), &(rhs->y)))
  {
    return false;
  }
  // z
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->z), &(rhs->z)))
  {
    return false;
  }
  // secs
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->secs), &(rhs->secs)))
  {
    return false;
  }
  return true;
}

bool
yolov8_msgs__msg__SegmentCenters__copy(
  const yolov8_msgs__msg__SegmentCenters * input,
  yolov8_msgs__msg__SegmentCenters * output)
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
  // id
  if (!rosidl_runtime_c__int16__Sequence__copy(
      &(input->id), &(output->id)))
  {
    return false;
  }
  // pixel_x
  if (!rosidl_runtime_c__int16__Sequence__copy(
      &(input->pixel_x), &(output->pixel_x)))
  {
    return false;
  }
  // pixel_y
  if (!rosidl_runtime_c__int16__Sequence__copy(
      &(input->pixel_y), &(output->pixel_y)))
  {
    return false;
  }
  // x
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->x), &(output->x)))
  {
    return false;
  }
  // y
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->y), &(output->y)))
  {
    return false;
  }
  // z
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->z), &(output->z)))
  {
    return false;
  }
  // secs
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->secs), &(output->secs)))
  {
    return false;
  }
  return true;
}

yolov8_msgs__msg__SegmentCenters *
yolov8_msgs__msg__SegmentCenters__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolov8_msgs__msg__SegmentCenters * msg = (yolov8_msgs__msg__SegmentCenters *)allocator.allocate(sizeof(yolov8_msgs__msg__SegmentCenters), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(yolov8_msgs__msg__SegmentCenters));
  bool success = yolov8_msgs__msg__SegmentCenters__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
yolov8_msgs__msg__SegmentCenters__destroy(yolov8_msgs__msg__SegmentCenters * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    yolov8_msgs__msg__SegmentCenters__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
yolov8_msgs__msg__SegmentCenters__Sequence__init(yolov8_msgs__msg__SegmentCenters__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolov8_msgs__msg__SegmentCenters * data = NULL;

  if (size) {
    data = (yolov8_msgs__msg__SegmentCenters *)allocator.zero_allocate(size, sizeof(yolov8_msgs__msg__SegmentCenters), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = yolov8_msgs__msg__SegmentCenters__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        yolov8_msgs__msg__SegmentCenters__fini(&data[i - 1]);
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
yolov8_msgs__msg__SegmentCenters__Sequence__fini(yolov8_msgs__msg__SegmentCenters__Sequence * array)
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
      yolov8_msgs__msg__SegmentCenters__fini(&array->data[i]);
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

yolov8_msgs__msg__SegmentCenters__Sequence *
yolov8_msgs__msg__SegmentCenters__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  yolov8_msgs__msg__SegmentCenters__Sequence * array = (yolov8_msgs__msg__SegmentCenters__Sequence *)allocator.allocate(sizeof(yolov8_msgs__msg__SegmentCenters__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = yolov8_msgs__msg__SegmentCenters__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
yolov8_msgs__msg__SegmentCenters__Sequence__destroy(yolov8_msgs__msg__SegmentCenters__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    yolov8_msgs__msg__SegmentCenters__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
yolov8_msgs__msg__SegmentCenters__Sequence__are_equal(const yolov8_msgs__msg__SegmentCenters__Sequence * lhs, const yolov8_msgs__msg__SegmentCenters__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!yolov8_msgs__msg__SegmentCenters__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
yolov8_msgs__msg__SegmentCenters__Sequence__copy(
  const yolov8_msgs__msg__SegmentCenters__Sequence * input,
  yolov8_msgs__msg__SegmentCenters__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(yolov8_msgs__msg__SegmentCenters);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    yolov8_msgs__msg__SegmentCenters * data =
      (yolov8_msgs__msg__SegmentCenters *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!yolov8_msgs__msg__SegmentCenters__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          yolov8_msgs__msg__SegmentCenters__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!yolov8_msgs__msg__SegmentCenters__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
