// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from yolov8_msgs:msg/ObjTracking.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__OBJ_TRACKING__STRUCT_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__OBJ_TRACKING__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'pos'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'vel'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__yolov8_msgs__msg__ObjTracking __attribute__((deprecated))
#else
# define DEPRECATED__yolov8_msgs__msg__ObjTracking __declspec(deprecated)
#endif

namespace yolov8_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ObjTracking_
{
  using Type = ObjTracking_<ContainerAllocator>;

  explicit ObjTracking_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    pos(_init),
    vel(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->object_id = 0;
    }
  }

  explicit ObjTracking_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    pos(_alloc, _init),
    vel(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->object_id = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _object_id_type =
    int16_t;
  _object_id_type object_id;
  using _pos_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _pos_type pos;
  using _vel_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _vel_type vel;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__object_id(
    const int16_t & _arg)
  {
    this->object_id = _arg;
    return *this;
  }
  Type & set__pos(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->pos = _arg;
    return *this;
  }
  Type & set__vel(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->vel = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    yolov8_msgs::msg::ObjTracking_<ContainerAllocator> *;
  using ConstRawPtr =
    const yolov8_msgs::msg::ObjTracking_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<yolov8_msgs::msg::ObjTracking_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<yolov8_msgs::msg::ObjTracking_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      yolov8_msgs::msg::ObjTracking_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<yolov8_msgs::msg::ObjTracking_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      yolov8_msgs::msg::ObjTracking_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<yolov8_msgs::msg::ObjTracking_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<yolov8_msgs::msg::ObjTracking_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<yolov8_msgs::msg::ObjTracking_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__yolov8_msgs__msg__ObjTracking
    std::shared_ptr<yolov8_msgs::msg::ObjTracking_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__yolov8_msgs__msg__ObjTracking
    std::shared_ptr<yolov8_msgs::msg::ObjTracking_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObjTracking_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->object_id != other.object_id) {
      return false;
    }
    if (this->pos != other.pos) {
      return false;
    }
    if (this->vel != other.vel) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObjTracking_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObjTracking_

// alias to use template instance with default allocator
using ObjTracking =
  yolov8_msgs::msg::ObjTracking_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace yolov8_msgs

#endif  // YOLOV8_MSGS__MSG__DETAIL__OBJ_TRACKING__STRUCT_HPP_
