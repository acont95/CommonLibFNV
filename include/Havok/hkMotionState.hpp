#pragma once
#include <cstdint>
#include "Havok/hkTransform.hpp"
#include "Havok/hkVector4.hpp"
#include "Havok/hkUFloat8.hpp"
#include "Havok/hkSweptTransform.hpp"

namespace CommonLib {

  class hkMotionState  
  {
    public:
      hkTransform m_transform;
      hkSweptTransform m_sweptTransform;
      hkVector4 m_deltaAngle;
      float m_objectRadius;
      float m_linearDamping;
      float m_angularDamping;
      hkUFloat8 m_maxLinearVelocity;
      hkUFloat8 m_maxAngularVelocity;
      std::uint8_t m_deactivationClass;
  };

  static_assert(sizeof(hkMotionState) == 0xB0, "hkMotionState has wrong size");
  
} // namespace CommonLib
