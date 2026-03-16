#pragma once

namespace CommonLib {

  class hkContainerHeapAllocator
  {
    public:
      hkContainerHeapAllocator();
      ~hkContainerHeapAllocator();
  };

  static_assert(sizeof(hkContainerHeapAllocator) == 0x1, "hkContainerHeapAllocator has wrong size");
  
} // namespace CommonLib
