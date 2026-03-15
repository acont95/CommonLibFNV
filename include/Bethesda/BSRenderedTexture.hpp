#pragma once
#include <cstdint>
#include "Gamebryo/NiObject.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiRenderTargetGroup.hpp"
#include "Gamebryo/NiRenderedTexture.hpp"

class BSRenderedTexture : NiObject
{
  public:
    BSRenderedTexture();
    virtual ~BSRenderedTexture();

    NiPointer<NiRenderTargetGroup> spGroup[6];
    NiPointer<NiRenderTargetGroup> spPreRestoreGroup;
    NiPointer<NiRenderTargetGroup> spRestoreGroup;
    NiPointer<NiRenderTargetGroup> spPostRestoreGroup;
    std::int32_t iAliasedType;
    NiPointer<NiRenderedTexture> spTexture[4];
};

static_assert(sizeof(BSRenderedTexture) == 0x40, "BSRenderedTexture has wrong size");
