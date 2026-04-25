#pragma once

namespace CommonLib {

  class hkContainerHeapAllocator;

  class alignas(16) hkpCdPointCollector
  {
    public:
      hkpCdPointCollector();
      virtual ~hkpCdPointCollector();

      float m_earlyOutDistance;
  };

  static_assert(sizeof(hkpCdPointCollector) == 0x10, "hkpCdPointCollector has wrong size");
  
} // namespace CommonLib
