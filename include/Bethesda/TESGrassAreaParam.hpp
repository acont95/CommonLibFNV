#pragma once
#include "Bethesda/TallGrassShaderProperty.hpp"

namespace CommonLib {

  class TESGrassAreaParam
  {
    public:

      TallGrassShaderProperty::GrassParam kGrassParam;
      float pfDensity[9];
  };

  static_assert(sizeof(TESGrassAreaParam) == 0x44, "TESGrassAreaParam has wrong size");
  
} // namespace CommonLib
