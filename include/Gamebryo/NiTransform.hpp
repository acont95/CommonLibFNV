#pragma once
#include "Gamebryo/NiMatrix3.hpp"

namespace CommonLib {

  class NiTransform
  {
    public:

      NiMatrix3 m_Rotate;
      NiPoint3 m_Translate;
      float m_fScale;
  };

  static_assert(sizeof(NiTransform) == 0x34, "NiTransform has wrong size");
  
} // namespace CommonLib
