#pragma once
#include <cstdint>
#include "Gamebryo/NiPoint3.hpp"

namespace CommonLib {

  class FurnitureMark
  {
    public:
      NiPoint3 Position;
      std::uint16_t sHeading;
      std::uint8_t cNumber;
  };

  static_assert(sizeof(FurnitureMark) == 0x10, "FurnitureMark has wrong size");
  
} // namespace CommonLib
