#pragma once
#include <cstdint>
#include "Havok/hkpRayHitCollector.hpp"
#include "Havok/hkpWorldRayCastOutput.hpp"

namespace CommonLib {

  class hkpClosestRayHitCollector : public hkpRayHitCollector
  {
    public:
      hkpClosestRayHitCollector();
      virtual ~hkpClosestRayHitCollector();

      hkpWorldRayCastOutput m_rayHit;
  };

  static_assert(sizeof(hkpClosestRayHitCollector) == 0x70, "hkpClosestRayHitCollector has wrong size");
  
} // namespace CommonLib
