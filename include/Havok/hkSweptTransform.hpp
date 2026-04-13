#pragma once
#include "Havok/hkVector4.hpp"
#include "Havok/hkQuaternion.hpp"

namespace CommonLib {

  class hkSweptTransform  
  {
    public:
      hkVector4 m_centerOfMass0;
      hkVector4 m_centerOfMass1;
      hkQuaternion m_rotation0;
      hkQuaternion m_rotation1;
      hkVector4 m_centerOfMassLocal;
  };

  static_assert(sizeof(hkSweptTransform) == 0x50, "hkSweptTransform has wrong size");
  
} // namespace CommonLib
