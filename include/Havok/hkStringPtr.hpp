#pragma once
#include <cstdint>

namespace CommonLib {

  class hkStringPtr
  {
    public:
      const char *m_stringAndFlag;
  };

  static_assert(sizeof(hkStringPtr) == 0x4, "hkStringPtr has wrong size");
  
} // namespace CommonLib
