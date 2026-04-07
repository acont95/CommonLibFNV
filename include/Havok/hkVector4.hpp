#pragma once
#include <xmmintrin.h>

namespace CommonLib {

  class hkVector4
  {
    public:
      __m128 m_quad; 
  };

  static_assert(sizeof(hkVector4) == 0x10, "hkVector4 has wrong size");
  
} // namespace CommonLib
