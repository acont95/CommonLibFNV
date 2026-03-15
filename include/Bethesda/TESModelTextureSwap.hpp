#pragma once
#include <cstdint>
#include "Bethesda/TESModel.hpp"
#include "Bethesda/BSSimpleList.hpp"
#include "Bethesda/BGSTextureSet.hpp"

class TESModelTextureSwap : public TESModel
{
  public:
    TESModelTextureSwap();
    ~TESModelTextureSwap();

    struct TEX_SWAP
    {
      BGSTextureSet* pNewTexture;
      std::int32_t iGeomIndex;
      char pGeomName[128];
    };

    BSSimpleList<TEX_SWAP*> TextureSwapList;
};

static_assert(sizeof(TESModelTextureSwap) == 0x20);
