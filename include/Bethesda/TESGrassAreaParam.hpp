#pragma once
#include "Bethesda/TallGrassShaderProperty.hpp"

class TESGrassAreaParam
{
  public:
    TESGrassAreaParam();
    ~TESGrassAreaParam();

    TallGrassShaderProperty::GrassParam kGrassParam;
    float pfDensity[9];
};

static_assert(sizeof(TESGrassAreaParam) == 0x44, "TESGrassAreaParam has wrong size");
