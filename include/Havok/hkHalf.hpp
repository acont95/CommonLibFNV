#pragma once
#include <cstdint>

namespace CommonLib {

  class hkHalf
  {
    public:
      hkHalf();
      ~hkHalf();

      std::int16_t m_value;
  };

  static_assert(sizeof(hkHalf) == 0x2, "hkHalf has wrong size");
  
} // namespace CommonLib
