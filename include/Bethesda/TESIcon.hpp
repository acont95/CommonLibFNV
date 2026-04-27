#pragma once
#include "Bethesda/TESTexture.hpp"

namespace CommonLib {

  class TESIcon : public TESTexture
  {
    public:

  };

  static_assert(sizeof(TESIcon) == 0xC, "TESIcon has wrong size");
  
} // namespace CommonLib
