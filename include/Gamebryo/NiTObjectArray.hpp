#pragma once
#include <cstdint>
#include "Gamebryo/NiTArray.hpp"
#include "Gamebryo/NiTNewInterface.hpp"

namespace CommonLib {

  template <typename T>
  class NiTObjectArray : public NiTArray<T, NiTNewInterface<T>>
  {
    public:

  };

  static_assert(sizeof(NiTObjectArray<std::uint32_t>) == 0x10, "NiTObjectArray has wrong size");
  
} // namespace CommonLib
