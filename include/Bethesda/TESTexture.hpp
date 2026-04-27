#pragma once
#include "Bethesda/BSStringT.hpp"
#include "Bethesda/BaseFormComponent.hpp"

namespace CommonLib {

  class TESTexture : public BaseFormComponent
  {
    public:

      BSStringT<char> TextureName;
  };

  static_assert(sizeof(TESTexture) == 0xC, "TESTexture has wrong size");
  
} // namespace CommonLib
