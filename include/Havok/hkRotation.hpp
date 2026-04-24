#pragma once
#include "Havok/hkMatrix3.hpp"

namespace CommonLib {

  class hkRotation : public hkMatrix3 {
    using hkMatrix3::hkMatrix3;
  };

  static_assert(sizeof(hkRotation) == 0x30, "hkRotation has wrong size");
  
} // namespace CommonLib
