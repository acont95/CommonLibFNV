#pragma once
#include <cstdint>
#include "Havok/hkVector4.hpp"
#include "Havok/hkBool.hpp"

namespace CommonLib {

  class hkpRayHitCollector
  {
    public:
      hkpRayHitCollector();
      virtual ~hkpRayHitCollector();

      float m_earlyOutHitFraction;
  };

  static_assert(sizeof(hkpRayHitCollector) == 0x8, "hkpRayHitCollector has wrong size");
  
} // namespace CommonLib
