#pragma once
#include "Gamebryo/NiColorA.hpp"
#include "Gamebryo/NiAnimationKey.hpp"

namespace CommonLib {

  class NiColorKey : public NiAnimationKey
  {
    public:

      NiColorA m_Color;
  };

  static_assert(sizeof(NiColorKey) == 0x14, "NiColorKey has wrong size");
  
} // namespace CommonLib
