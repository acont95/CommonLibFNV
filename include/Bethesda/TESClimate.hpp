#pragma once
#include "Bethesda/TESForm.hpp"
#include "Bethesda/TESModel.hpp"
#include "Bethesda/TESWeatherList.hpp"
#include "Bethesda/TESTexture.hpp"

class TESClimate : TESForm
{
  public:
    TESClimate();
    virtual ~TESClimate();

    enum TextureType : __int32
    {
      TX_SUN = 0x0,
      TX_GLARE = 0x1,
      NUM_TEXTURES = 0x2,
    };

    enum HourlyIncrements : __int32
    {
      HOURLY_INCREMENTS = 0x6,
    };

    enum TransTime : __int32
    {
      SUNRISE_BEGIN = 0x0,
      SUNRISE_END = 0x1,
      SUNSET_BEGIN = 0x2,
      SUNSET_END = 0x3,
      NUM_TRANS_TIMES = 0x4,
    };

    enum MiscData : __int32
    {
      VOLATILITY = 0x4,
      MOON_DATA = 0x5,
      NUM_SLIDERS = 0x6,
    };

    TESModel mNightSky;
    TESWeatherList weatherList;
    TESTexture txSkyObjects[2];
    unsigned __int8 ucData[6];
};

static_assert(sizeof(TESClimate) == 0x58, "TESClimate has wrong size");
