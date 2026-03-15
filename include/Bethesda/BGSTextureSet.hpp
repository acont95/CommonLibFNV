#pragma once
#include <cstdint>
#include "Bethesda/TESBoundObject.hpp"
#include "Bethesda/BSTextureSet.hpp"
#include "Bethesda/TESTexture.hpp"
#include "Bethesda/DecalData.hpp"
#include "Bethesda/BSFileEntry.hpp"

class BGSTextureSet : TESBoundObject, BSTextureSet
{
  public:
    BGSTextureSet();
    ~BGSTextureSet();

    TESTexture pTextures[7];
    DecalData* pDecalData;
    std::uint16_t iFlags;
    BSFileEntry* pTextureFileEntries[7];
};

static_assert(sizeof(BGSTextureSet) == 0xB0, "BGSTextureSet has wrong size");
