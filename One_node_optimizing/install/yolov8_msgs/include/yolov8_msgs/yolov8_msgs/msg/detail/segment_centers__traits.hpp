// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from yolov8_msgs:msg/SegmentCenters.idl
// generated code does not contain a copyright notice

#ifndef YOLOV8_MSGS__MSG__DETAIL__SEGMENT_CENTERS__TRAITS_HPP_
#define YOLOV8_MSGS__MSG__DETAIL__SEGMENT_CENTERS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "yolov8_msgs/msg/detail/segment_centers__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace yolov8_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SegmentCenters & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: id
  {
    if (msg.id.size() == 0) {
      out << "id: []";
    } else {
      out << "id: [";
      size_t pending_items = msg.id.size();
      for (auto item : msg.id) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: pixel_x
  {
    if (msg.pixel_x.size() == 0) {
      out << "pixel_x: []";
    } else {
      out << "pixel_x: [";
      size_t pending_items = msg.pixel_x.size();
      for (auto item : msg.pixel_x) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: pixel_y
  {
    if (msg.pixel_y.size() == 0) {
      out << "pixel_y: []";
    } else {
      out << "pixel_y: [";
      size_t pending_items = msg.pixel_y.size();
      for (auto item : msg.pixel_y) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: x
  {
    if (msg.x.size() == 0) {
      out << "x: []";
    } else {
      out << "x: [";
      size_t pending_items = msg.x.size();
      for (auto item : msg.x) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: y
  {
    if (msg.y.size() == 0) {
      out << "y: []";
    } else {
      out << "y: [";
      size_t pending_items = msg.y.size();
      for (auto item : msg.y) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: z
  {
    if (msg.z.size() == 0) {
      out << "z: []";
    } else {
      out << "z: [";
      size_t pending_items = msg.z.size();
      for (auto item : msg.z) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: secs
  {
    if (msg.secs.size() == 0) {
      out << "secs: []";
    } else {
      out << "secs: [";
      size_t pending_items = msg.secs.size();
      for (auto item : msg.secs) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SegmentCenters & msg,
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

  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.id.size() == 0) {
      out << "id: []\n";
    } else {
      out << "id:\n";
      for (auto item : msg.id) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: pixel_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.pixel_x.size() == 0) {
      out << "pixel_x: []\n";
    } else {
      out << "pixel_x:\n";
      for (auto item : msg.pixel_x) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: pixel_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.pixel_y.size() == 0) {
      out << "pixel_y: []\n";
    } else {
      out << "pixel_y:\n";
      for (auto item : msg.pixel_y) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.x.size() == 0) {
      out << "x: []\n";
    } else {
      out << "x:\n";
      for (auto item : msg.x) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.y.size() == 0) {
      out << "y: []\n";
    } else {
      out << "y:\n";
      for (auto item : msg.y) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.z.size() == 0) {
      out << "z: []\n";
    } else {
      out << "z:\n";
      for (auto item : msg.z) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: secs
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.secs.size() == 0) {
      out << "secs: []\n";
    } else {
      out << "secs:\n";
      for (auto item : msg.secs) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SegmentCenters & msg, bool use_flow_style = false)
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
  const yolov8_msgs::msg::SegmentCenters & msg,
  std::ostream & out, size_t indentation = 0)
{
  yolov8_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use yolov8_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const yolov8_msgs::msg::SegmentCenters & msg)
{
  return yolov8_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<yolov8_msgs::msg::SegmentCenters>()
{
  return "yolov8_msgs::msg::SegmentCenters";
}

template<>
inline const char * name<yolov8_msgs::msg::SegmentCenters>()
{
  return "yolov8_msgs/msg/SegmentCenters";
}

template<>
struct has_fixed_size<yolov8_msgs::msg::SegmentCenters>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<yolov8_msgs::msg::SegmentCenters>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<yolov8_msgs::msg::SegmentCenters>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // YOLOV8_MSGS__MSG__DETAIL__SEGMENT_CENTERS__TRAITS_HPP_
