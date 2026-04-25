#pragma once
#include "Havok/hkInplaceArray.hpp"
#include "Havok/hkpRootCdPoint.hpp"
#include "Havok/hkpCdPointCollector.hpp"

namespace CommonLib {

  class hkContainerHeapAllocator;

  class alignas(16) hkpAllCdPointCollector : public hkpCdPointCollector
  {
    public:
      hkpAllCdPointCollector();
      virtual ~hkpAllCdPointCollector();

      hkInplaceArray<hkpRootCdPoint, 8, hkContainerHeapAllocator> m_hits;
  };

  static_assert(sizeof(hkpAllCdPointCollector) == 0x3A0, "hkpAllCdPointCollector has wrong size");
  
} // namespace CommonLib
