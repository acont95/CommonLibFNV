#pragma once
#include <cstdint>
#include "Bethesda/TESForm.hpp"

namespace CommonLib {

  class BGSTextureSet;
  class TESGrass;

  class TESLandTexture : public TESForm 
  {
    public:
      TESLandTexture();
      ~TESLandTexture();

      struct TEXTURE_HAVOK_DATA
      {
        std::uint8_t cMaterialType;
        std::uint8_t cFriction;
        std::uint8_t cRestitution;
      };

      BGSTextureSet* pTextureSet;
      TEXTURE_HAVOK_DATA HavokData;
      std::uint8_t cSpecularExponent;
      BSSimpleList<TESGrass*> TextureGrassList;
  };

  static_assert(sizeof(TESLandTexture) == 0x28, "TESLandTexture has wrong size");
  
} // namespace CommonLib
