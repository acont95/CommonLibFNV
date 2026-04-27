#pragma once
#include "Gamebryo/NiObject.hpp"

namespace CommonLib {

  class NiInterpolator : public NiObject
  {
    public:

      float m_fLastTime;
  };

  static_assert(sizeof(NiInterpolator) == 0xC, "NiInterpolator has wrong size");
  
} // namespace CommonLib
