// Generated by gencpp from file exo_angle_control/ExoAngleChange.msg
// DO NOT EDIT!


#ifndef EXO_ANGLE_CONTROL_MESSAGE_EXOANGLECHANGE_H
#define EXO_ANGLE_CONTROL_MESSAGE_EXOANGLECHANGE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace exo_angle_control
{
template <class ContainerAllocator>
struct ExoAngleChange_
{
  typedef ExoAngleChange_<ContainerAllocator> Type;

  ExoAngleChange_()
    : hipLeft(0)
    , hipRight(0)
    , kneeLeft(0)
    , kneeRight(0)  {
    }
  ExoAngleChange_(const ContainerAllocator& _alloc)
    : hipLeft(0)
    , hipRight(0)
    , kneeLeft(0)
    , kneeRight(0)  {
  (void)_alloc;
    }



   typedef uint32_t _hipLeft_type;
  _hipLeft_type hipLeft;

   typedef uint32_t _hipRight_type;
  _hipRight_type hipRight;

   typedef uint32_t _kneeLeft_type;
  _kneeLeft_type kneeLeft;

   typedef uint32_t _kneeRight_type;
  _kneeRight_type kneeRight;





  typedef boost::shared_ptr< ::exo_angle_control::ExoAngleChange_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::exo_angle_control::ExoAngleChange_<ContainerAllocator> const> ConstPtr;

}; // struct ExoAngleChange_

typedef ::exo_angle_control::ExoAngleChange_<std::allocator<void> > ExoAngleChange;

typedef boost::shared_ptr< ::exo_angle_control::ExoAngleChange > ExoAngleChangePtr;
typedef boost::shared_ptr< ::exo_angle_control::ExoAngleChange const> ExoAngleChangeConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::exo_angle_control::ExoAngleChange_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::exo_angle_control::ExoAngleChange_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::exo_angle_control::ExoAngleChange_<ContainerAllocator1> & lhs, const ::exo_angle_control::ExoAngleChange_<ContainerAllocator2> & rhs)
{
  return lhs.hipLeft == rhs.hipLeft &&
    lhs.hipRight == rhs.hipRight &&
    lhs.kneeLeft == rhs.kneeLeft &&
    lhs.kneeRight == rhs.kneeRight;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::exo_angle_control::ExoAngleChange_<ContainerAllocator1> & lhs, const ::exo_angle_control::ExoAngleChange_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace exo_angle_control

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::exo_angle_control::ExoAngleChange_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::exo_angle_control::ExoAngleChange_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::exo_angle_control::ExoAngleChange_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::exo_angle_control::ExoAngleChange_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::exo_angle_control::ExoAngleChange_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::exo_angle_control::ExoAngleChange_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::exo_angle_control::ExoAngleChange_<ContainerAllocator> >
{
  static const char* value()
  {
    return "32bc8f464253af317aba999b23bbafc7";
  }

  static const char* value(const ::exo_angle_control::ExoAngleChange_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x32bc8f464253af31ULL;
  static const uint64_t static_value2 = 0x7aba999b23bbafc7ULL;
};

template<class ContainerAllocator>
struct DataType< ::exo_angle_control::ExoAngleChange_<ContainerAllocator> >
{
  static const char* value()
  {
    return "exo_angle_control/ExoAngleChange";
  }

  static const char* value(const ::exo_angle_control::ExoAngleChange_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::exo_angle_control::ExoAngleChange_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint32 hipLeft\n"
"uint32 hipRight\n"
"uint32 kneeLeft\n"
"uint32 kneeRight\n"
;
  }

  static const char* value(const ::exo_angle_control::ExoAngleChange_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::exo_angle_control::ExoAngleChange_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.hipLeft);
      stream.next(m.hipRight);
      stream.next(m.kneeLeft);
      stream.next(m.kneeRight);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ExoAngleChange_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::exo_angle_control::ExoAngleChange_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::exo_angle_control::ExoAngleChange_<ContainerAllocator>& v)
  {
    s << indent << "hipLeft: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.hipLeft);
    s << indent << "hipRight: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.hipRight);
    s << indent << "kneeLeft: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.kneeLeft);
    s << indent << "kneeRight: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.kneeRight);
  }
};

} // namespace message_operations
} // namespace ros

#endif // EXO_ANGLE_CONTROL_MESSAGE_EXOANGLECHANGE_H
