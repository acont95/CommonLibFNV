#pragma once
#include <cstdint>

namespace CommonLib {

  class ColorPair
  {
    public:
      std::uint32_t iID;
      std::uint32_t iColor;
  };

  static_assert(sizeof(ColorPair) == 0x8, "ColorPair has wrong size");
  
} // namespace CommonLib
