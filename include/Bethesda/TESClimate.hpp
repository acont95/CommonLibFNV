#pragma once
#include <cstdint>
#include "Bethesda/TESWeatherList.hpp"
#include "Bethesda/TESForm.hpp"
#include "Bethesda/TESModel.hpp"
#include "Bethesda/TESTexture.hpp"

class TESClimate : public TESForm
{
  public:
    TESClimate();
    virtual ~TESClimate();

    enum TextureType : std::int32_t
    {
      TX_SUN = 0x0,
      TX_GLARE = 0x1,
      NUM_TEXTURES = 0x2,
    };

    enum HourlyIncrements : std::int32_t
    {
      HOURLY_INCREMENTS = 0x6,
    };

    enum TransTime : std::int32_t
    {
      SUNRISE_BEGIN = 0x0,
      SUNRISE_END = 0x1,
      SUNSET_BEGIN = 0x2,
      SUNSET_END = 0x3,
      NUM_TRANS_TIMES = 0x4,
    };

    enum MiscData : std::int32_t
    {
      VOLATILITY = 0x4,
      MOON_DATA = 0x5,
      NUM_SLIDERS = 0x6,
    };

    TESModel mNightSky;
    TESWeatherList weatherList;
    TESTexture txSkyObjects[2];
    std::uint8_t ucData[6];
};

static_assert(sizeof(TESClimate) == 0x58, "TESClimate has wrong size");
