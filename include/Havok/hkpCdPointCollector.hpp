#pragma once

namespace CommonLib {

  class hkContainerHeapAllocator;

  class hkpCdPointCollector
  {
    public:
      hkpCdPointCollector();
      virtual ~hkpCdPointCollector();

      float m_earlyOutDistance;
  };

  static_assert(sizeof(hkpCdPointCollector) == 0x8, "hkpCdPointCollector has wrong size");
  
} // namespace CommonLib
