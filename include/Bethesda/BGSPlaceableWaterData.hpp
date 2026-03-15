#pragma once
#include "Bethesda/TESWaterForm.hpp"

class BGSPlaceableWaterData
{
  public:
    BGSPlaceableWaterData();
    ~BGSPlaceableWaterData();

    unsigned int ulFlags;
    TESWaterForm *pWaterType;
};

static_assert(sizeof(BGSPlaceableWaterData) == 0x8, "BGSPlaceableWaterData has wrong size");
