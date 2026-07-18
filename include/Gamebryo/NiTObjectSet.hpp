#pragma once
#include "Gamebryo/NiTSet.hpp"

namespace CommonLib {

  template <typename T>
  class NiTObjectSet : public NiTSet<T, NiTNewInterface<T> >
  {};

  static_assert(sizeof(NiTObjectSet<std::uint32_t>) == 0xC, "NiTPointerAllocator has wrong size");
  
} // namespace CommonLib
