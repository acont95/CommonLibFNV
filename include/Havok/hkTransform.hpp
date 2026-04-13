#pragma once
#include "Havok/hkVector4.hpp"
#include "Havok/hkRotation.hpp"

namespace CommonLib {

  class hkTransform   
  {
    public:
      hkRotation m_rotation;
      hkVector4 m_translation;
  };

  static_assert(sizeof(hkTransform ) == 0x40, "hkTransform  has wrong size");
  
} // namespace CommonLib
