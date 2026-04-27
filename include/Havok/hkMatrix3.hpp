#pragma once
#include "Havok/hkVector4.hpp"

namespace CommonLib {

  class hkMatrix3
  {
    public:

      hkMatrix3();
      hkMatrix3(hkVector4& col0, hkVector4& col1, hkVector4& col2);
      void transpose();
      void setTranspose(const hkMatrix3& s);

      hkVector4 m_col0;
      hkVector4 m_col1;
      hkVector4 m_col2;
  };

  static_assert(sizeof(hkMatrix3) == 0x30, "hkMatrix3 has wrong size");
  
} // namespace CommonLib
