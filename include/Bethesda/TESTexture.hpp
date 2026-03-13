#pragma once
#include "Bethesda/BSStringT.hpp"
#include "Bethesda/BaseFormComponent.hpp"

class TESTexture : BaseFormComponent
{
  public:
    TESTexture();
    ~TESTexture();

    BSStringT<char> TextureName;
};

static_assert(sizeof(TESTexture) == 0xC, "TESTexture has wrong size");
