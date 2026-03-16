#pragma once
#include <cstdint>
#include "Gamebryo/NiTPointerAllocator.hpp"
#include "Gamebryo/NiTPointerListBase.hpp"

namespace CommonLib {

  template <typename T>
  class NiTPointerListSingleThread : public NiTPointerListBase<NiTPointerAllocator<std::uint32_t>, T>
  {
    public:
      NiTPointerListSingleThread();
      ~NiTPointerListSingleThread();
  };

  static_assert(sizeof(NiTPointerListSingleThread<void*>) == 0xC, "NiTPointerListSingleThread has wrong size");
    
} // namespace CommonLib
