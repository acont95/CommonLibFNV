#pragma once
#include <cstdint>
#include "Bethesda/TESBoundObject.hpp"
#include "Bethesda/TESModel.hpp"

class TESGrass : public TESBoundObject, public TESModel
{
  public:
    TESGrass();
    ~TESGrass();

    enum GRASS_WATER_STATE : std::int32_t
    {
      GWS_ABOVE_ONLY_ATLEAST = 0x0,
      GWS_ABOVE_ONLY_ATMOST = 0x1,
      GWS_BELOW_ONLY_ATLEAST = 0x2,
      GWS_BELOW_ONLY_ATMOST = 0x3,
      GWS_BOTH_ATLEAST = 0x4,
      GWS_BOTH_ATMOST = 0x5,
      GWS_BOTH_ATMOST_ABOVE = 0x6,
      GWS_BOTH_ATMOST_BELOW = 0x7,
      GWS_COUNT = 0x8,
    };

    struct GRASS_DATA
    {
      std::uint8_t cDensity;
      std::uint8_t cMinSlopeDegrees;
      std::uint8_t cMaxSlopeDegrees;
      std::uint16_t sDistanceFromWaterLevel;
      TESGrass::GRASS_WATER_STATE eUnderwater;
      float fPositionRange;
      float fHeightRange;
      float fColorRange;
      float fWavePeriod;
      char cFlags;
    };

    TESGrass::GRASS_DATA Data;
};

static_assert(sizeof(TESGrass) == 0x68, "TESGrass has wrong size");
