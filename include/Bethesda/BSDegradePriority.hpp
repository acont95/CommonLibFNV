#pragma once
#include <cstdint>

namespace CommonLib {

  class BSDegradePriority
  {
    public:

      std::uint8_t cPriorityL;
      std::uint8_t cPriorityH;
      std::uint8_t cPriorityC;
      std::uint8_t cState;
  };

  static_assert(sizeof(BSDegradePriority) == 0x4, "BSDegradePriority has wrong size");
  
} // namespace CommonLib
