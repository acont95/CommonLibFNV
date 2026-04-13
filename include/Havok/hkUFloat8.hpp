#pragma once
#include <cstdint>

namespace CommonLib {

  class hkUFloat8  
  {
    public:
      std::uint8_t m_value;
  };

  static_assert(sizeof(hkUFloat8) == 0x1, "hkUFloat8 has wrong size");
  
} // namespace CommonLib
