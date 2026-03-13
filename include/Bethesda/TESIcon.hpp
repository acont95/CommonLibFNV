#pragma once
#include "Bethesda/TESTexture.hpp"

class TESIcon : TESTexture
{
  public:
    TESIcon();
    ~TESIcon();
};

static_assert(sizeof(TESIcon) == 0xC, "TESIcon has wrong size");
