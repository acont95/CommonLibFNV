#pragma once
#include "Bethesda/BGSPlaceableWaterData.hpp"

class BGSPlaceableWater : TESBoundObject, TESModel
{
  public:
    BGSPlaceableWater();
    virtual ~BGSPlaceableWater();

    BGSPlaceableWaterData Data;
};

static_assert(sizeof(BGSPlaceableWater) == 0x50, "BGSPlaceableWater has wrong size");
