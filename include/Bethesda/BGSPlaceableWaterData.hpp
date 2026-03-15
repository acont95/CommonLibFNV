#pragma once
#include <cstdint>
#include "Bethesda/TESWaterForm.hpp"

class BGSPlaceableWaterData
{
  public:
    BGSPlaceableWaterData();
    ~BGSPlaceableWaterData();

    std::uint32_t ulFlags;
    TESWaterForm *pWaterType;
};

static_assert(sizeof(BGSPlaceableWaterData) == 0x8, "BGSPlaceableWaterData has wrong size");
