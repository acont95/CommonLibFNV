#pragma once
#include "Havok/hkVector4.hpp"

namespace CommonLib {

  class hkContactPoint
  {
    public:

      hkVector4 m_position;
      hkVector4 m_separatingNormal;
  };

  static_assert(sizeof(hkContactPoint) == 0x20, "hkContactPoint has wrong size");
  
} // namespace CommonLib
