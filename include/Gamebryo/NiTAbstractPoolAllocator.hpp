#pragma once

namespace CommonLib {

  template <typename T>
  class NiTAbstractPoolAllocator
  {
    public:
      NiTAbstractPoolAllocator();
      ~NiTAbstractPoolAllocator();
  };

  static_assert(sizeof(NiTAbstractPoolAllocator<void*>) == 0x1, "NiTAbstractPoolAllocator has wrong size");
  
} // namespace CommonLib
