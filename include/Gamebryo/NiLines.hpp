#pragma once
#include "Gamebryo/NiGeometry.hpp"

namespace CommonLib {

  class NiLines : public NiGeometry
  {
    public:

  };

  static_assert(sizeof(NiLines) == 0xC4, "NiLines has wrong size");
  
} // namespace CommonLib
