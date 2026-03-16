#pragma once
#include "Gamebryo/NiInterpolator.hpp"

namespace CommonLib {

  class NiKeyBasedInterpolator : public NiInterpolator
  {
    public:
      NiKeyBasedInterpolator();
      ~NiKeyBasedInterpolator();
  };

  static_assert(sizeof(NiKeyBasedInterpolator) == 0xC, "NiKeyBasedInterpolator has wrong size");
  
} // namespace CommonLib
