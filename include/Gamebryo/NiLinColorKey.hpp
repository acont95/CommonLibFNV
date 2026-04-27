#pragma once
#include "Gamebryo/NiColorKey.hpp"

namespace CommonLib {

  class NiLinColorKey : public NiColorKey
  {
    public:

  };

  static_assert(sizeof(NiLinColorKey) == 0x14, "NiLinColorKey has wrong size");
  
} // namespace CommonLib
