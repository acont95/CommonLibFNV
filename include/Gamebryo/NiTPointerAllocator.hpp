#pragma once
#include <cstdint>
#include "Gamebryo/NiTAbstractPoolAllocator.hpp"

namespace CommonLib {

  template <typename T>
  class NiTPointerAllocator : public NiTAbstractPoolAllocator<T>
  {
    public:

  };

  static_assert(sizeof(NiTPointerAllocator<std::uint32_t>) == 0x1, "NiTPointerAllocator has wrong size");
  
} // namespace CommonLib
