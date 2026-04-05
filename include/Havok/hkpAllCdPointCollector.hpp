#pragma once
#include "Havok/hkInplaceArray.hpp"
#include "Havok/hkpRootCdPoint.hpp"
#include "Havok/hkpCdPointCollector.hpp"

namespace CommonLib {

  class hkContainerHeapAllocator;

  class hkpAllCdPointCollector : public hkpCdPointCollector
  {
    public:
      hkpAllCdPointCollector();
      virtual ~hkpAllCdPointCollector();

      hkInplaceArray<hkpRootCdPoint, 8, hkContainerHeapAllocator> m_hits;
  };

  static_assert(sizeof(hkpAllCdPointCollector) == 0x3A0, "hkpAllCdPointCollector has wrong size");
  
} // namespace CommonLib
