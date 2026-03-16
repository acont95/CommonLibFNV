#pragma once
#include "Bethesda/TESTexture.hpp"

class TESTexture1024 : public TESTexture
{
  public:
    TESTexture1024();
    virtual ~TESTexture1024();
};

static_assert(sizeof(TESTexture1024) == 0xC, "TESTexture1024 has wrong size");
