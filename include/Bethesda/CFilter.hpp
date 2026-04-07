#pragma once
#include <cstdint>

namespace CommonLib {

  class CFilter
  {
    public:
      std::uint32_t iFilter;
  };

  static_assert(sizeof(CFilter) == 0x4, "CFilter has wrong size");
  
} // namespace CommonLib
