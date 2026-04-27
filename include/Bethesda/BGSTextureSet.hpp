#pragma once
#include <cstdint>
#include "Bethesda/BSTextureSet.hpp"
#include "Bethesda/TESBoundObject.hpp"
#include "Bethesda/TESTexture.hpp"

namespace CommonLib {

  class DecalData;
  class BSFileEntry;

  class BGSTextureSet : public TESBoundObject, public BSTextureSet
  {
    public:

      TESTexture pTextures[7];
      DecalData* pDecalData;
      std::uint16_t iFlags;
      BSFileEntry* pTextureFileEntries[7];
  };

  static_assert(sizeof(BGSTextureSet) == 0xB0, "BGSTextureSet has wrong size");
  
} // namespace CommonLib
