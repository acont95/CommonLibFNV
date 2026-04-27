#pragma once
#include "Gamebryo/NiPoint3.hpp"

namespace CommonLib {

  class NiMatrix3
  {
    public:
      NiPoint3 m_pEntry[3];

      NiMatrix3();
      NiMatrix3(const NiPoint3& row1, const NiPoint3& row2, const NiPoint3& row3);
      void ToEulerAnglesZXY(float &rfZAngle, float &rfXAngle, float &rfYAngle) const;
      void FromEulerAnglesZXY(float fZAngle, float fXAngle, float fYAngle);
      NiMatrix3 Multiply(const NiMatrix3 &mat) const;
      bool Inverse(NiMatrix3& inv) const;
      NiMatrix3 Inverse() const;
      NiMatrix3 Transpose() const;

      static const NiMatrix3 ZERO;
      static const NiMatrix3 IDENTITY;
  };

  static_assert(sizeof(NiMatrix3) == 0x24, "NiMatrix3 has wrong size");
  
} // namespace CommonLib
