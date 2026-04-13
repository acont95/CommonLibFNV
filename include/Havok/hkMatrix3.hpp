#pragma once
#include "Havok/hkVector4.hpp"

namespace CommonLib {

  class hkMatrix3
  {
    public:
      hkVector4 m_col0;
      hkVector4 m_col1;
      hkVector4 m_col2;
  };

  static_assert(sizeof(hkMatrix3) == 0x30, "hkMatrix3 has wrong size");
  
} // namespace CommonLib
