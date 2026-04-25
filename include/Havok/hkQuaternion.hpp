#pragma once
#include "Havok/hkVector4.hpp"

namespace CommonLib {

  class alignas(16) hkQuaternion  
  {
    public:
      hkVector4 m_vec;
  };

  static_assert(sizeof(hkQuaternion) == 0x10, "hkQuaternion has wrong size");
  
} // namespace CommonLib
