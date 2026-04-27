#pragma once

namespace CommonLib {

  template <typename T>
  class NiTDefaultAllocator
  {
    public:

  };

  template <typename T>
  using DFALL = NiTDefaultAllocator<T>;

  static_assert(sizeof(NiTDefaultAllocator<void*>) == 0x1, "NiTDefaultAllocator has wrong size");
  
} // namespace CommonLib
