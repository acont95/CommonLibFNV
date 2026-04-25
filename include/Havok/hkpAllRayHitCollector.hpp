#pragma once
#include <cstdint>
#include "Havok/hkpRayHitCollector.hpp"
#include "Havok/hkInplaceArray.hpp"
#include "Havok/hkpWorldRayCastOutput.hpp"

namespace CommonLib {

  class hkContainerHeapAllocator;

  class hkpAllRayHitCollector : public hkpRayHitCollector
  {
    public:
      hkpAllRayHitCollector();
      virtual ~hkpAllRayHitCollector();

      hkInplaceArray<hkpWorldRayCastOutput, 8, hkContainerHeapAllocator> m_hits;
  };

  static_assert(sizeof(hkpAllRayHitCollector) == 0x320, "hkpAllRayHitCollector has wrong size");
  
} // namespace CommonLib
