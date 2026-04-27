#pragma once
#include "Gamebryo/NiTPointerListBase.hpp"
#include "Gamebryo/NiTPointerAllocator.hpp"

namespace CommonLib {

  template <typename T>
  class NiTPointerList : public NiTPointerListBase<NiTPointerAllocator<std::uint32_t>, T>
  {
    public:

  };

  static_assert(sizeof(NiTPointerList<void*>) == 0xC, "NiTPointerList has wrong size");
  
} // namespace CommonLib
