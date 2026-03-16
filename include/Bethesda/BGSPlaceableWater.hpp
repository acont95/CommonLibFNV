#pragma once
#include "Bethesda/BGSPlaceableWaterData.hpp"
#include "Bethesda/TESBoundObject.hpp"
#include "Bethesda/TESModel.hpp"

class BGSPlaceableWater : public TESBoundObject, public TESModel
{
  public:
    BGSPlaceableWater();
    virtual ~BGSPlaceableWater();

    BGSPlaceableWaterData Data;
};

static_assert(sizeof(BGSPlaceableWater) == 0x50, "BGSPlaceableWater has wrong size");
