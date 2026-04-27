#pragma once
#include <cstdint>

namespace CommonLib {

  template <typename T>
  class NiTNewInterface
  {
    public:

  };

  static_assert(sizeof(NiTNewInterface<std::uint32_t>) == 0x1, "NiTNewInterface has wrong size");
  
} // namespace CommonLib
