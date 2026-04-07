#pragma once
#include <cstdint>
#include "Havok/hkVector4.hpp"
#include "Havok/hkBool.hpp"

namespace CommonLib {

  class hkAabb
  {
    public:
      hkAabb();
      ~hkAabb();

      hkVector4 m_min;
      hkVector4 m_max;
  };

  static_assert(sizeof(hkAabb) == 0x20, "hkAabb has wrong size");
  
} // namespace CommonLib
