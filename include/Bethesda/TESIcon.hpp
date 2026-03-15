#pragma once
#include "Bethesda/TESTexture.hpp"

class TESIcon : public TESTexture
{
  public:
    TESIcon();
    ~TESIcon();
};

static_assert(sizeof(TESIcon) == 0xC, "TESIcon has wrong size");
