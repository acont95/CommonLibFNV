#pragma once
#include <cstdint>
#include "Gamebryo/NiTMapBase.hpp"
#include "Gamebryo/NiTPointerAllocator.hpp"

namespace CommonLib {

  template <typename Key, typename Value>
  class NiTPointerMap : public NiTMapBase<NiTPointerAllocator<std::uint32_t>, Key, Value>
  {
    public:
      NiTPointerMap();
      ~NiTPointerMap();
  };

  static_assert(sizeof(NiTPointerMap<void*, void*>) == 0x10, "NiTPointerMap has wrong size");
  
} // namespace CommonLib
