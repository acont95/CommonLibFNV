#pragma once
#include "Gamebryo/NiAnimationKey.hpp"

namespace CommonLib {

  class NiFloatKey : public NiAnimationKey
  {
    public:

      float m_fValue;
  };

  static_assert(sizeof(NiFloatKey) == 0x8, "NiFloatKey has wrong size");
  
} // namespace CommonLib
