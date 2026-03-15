#pragma once
#include <xmmintrin.h>

class hkVector4
{
  public:
    hkVector4();
    ~hkVector4();

    __m128 m_quad; 
};

static_assert(sizeof(hkVector4) == 0x10, "hkVector4 has wrong size");
