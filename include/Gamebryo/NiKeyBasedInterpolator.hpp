#pragma once
#include "Gamebryo/NiInterpolator.hpp"

namespace CommonLib {

  class NiKeyBasedInterpolator : public NiInterpolator
  {
    public:

  };

  static_assert(sizeof(NiKeyBasedInterpolator) == 0xC, "NiKeyBasedInterpolator has wrong size");
  
} // namespace CommonLib
