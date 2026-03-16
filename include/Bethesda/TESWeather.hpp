#pragma once
#include <cstdint>
#include "Bethesda/TESForm.hpp"
#include "Bethesda/TESTexture1024.hpp"   
#include "Bethesda/TESModel.hpp"   
#include "Bethesda/ImageSpaceParameterData.hpp"     
#include "Bethesda/TESImageSpaceModifiableCountForm.hpp" 

class TESWeather : public TESForm, public TESImageSpaceModifiableCountForm<6>
{
  public:
    TESWeather();
    ~TESWeather();

    enum SoundType : std::int32_t
    {
      WST_DEFAULT = 0x0,
      WST_PRECIP = 0x1,
      WST_WIND = 0x2,
      WST_THUNDER = 0x3,
      WST_COUNT = 0x4,
    };

    enum WarningStatus : std::int32_t
    {
      ENABLED = 0x0,
      SKIP = 0x2,
    };

    enum WeatherData : std::int32_t
    {
      WD_WIND_SPEED = 0x0,
      WD_CLOUD_SPEED = 0x1,
      WD_CLOUD_SPEED_UNUSED = 0x2,
      WD_TRANS_DELTA = 0x3,
      WD_SUN_GLARE = 0x4,
      WD_SUN_DAMAGE = 0x5,
      WD_DIVIDER1 = 0x6,
      WD_BEGIN_PRECIP = 0x6,
      WD_END_PRECIP = 0x7,
      WD_BEGIN_THUNDER = 0x8,
      WD_END_THUNDER = 0x9,
      WD_THUNDER_FREQ = 0xA,
      WD_DIVIDER2 = 0xB,
      WD_FLAGS = 0xB,
      WD_LIGHTNING_R = 0xC,
      WD_LIGHTNING_G = 0xD,
      WD_LIGHTNING_B = 0xE,
      WD_DIVIDER3 = 0xF,
      WD_COUNT = 0xF,
    };

    enum FogData : std::int32_t
    {
      NEAR_DIST_DAY = 0x0,
      FAR_DIST_DAY = 0x1,
      NEAR_DIST_NIGHT = 0x2,
      FAR_DIST_NIGHT = 0x3,
      FOG_POWER_DAY = 0x4,
      FOG_POWER_NIGHT = 0x5,
      FD_COUNT = 0x6,
    };

    enum ColorType : std::int32_t
    {
      SKY_UPPER = 0x0,
      FOG = 0x1,
      CLOUD_LAYER = 0x2,
      AMBIENT = 0x3,
      SUNLIGHT = 0x4,
      SUN = 0x5,
      STARS = 0x6,
      SKY_LOWER = 0x7,
      HORIZON = 0x8,
      CLOUDS_UNUSED = 0x9,
    };

    enum ColorTime : std::int32_t
    {
      SUNRISE = 0x0,
      DAY = 0x1,
      SUNSET = 0x2,
      NIGHT = 0x3,
      NOON = 0x4,
      MIDNIGHT = 0x5,
      NUM_TIMES = 0x6,
    };

    enum WeatherDataFlag : std::int32_t
    {
      WDF_PLEASANT = 0x1,
      WDF_CLOUDY = 0x2,
      WDF_RAINY = 0x4,
      WDF_SNOW = 0x8,
    };

    enum HDRDataType : std::int32_t
    {
      HDR_EYE_ADAPT_SPEED = 0x0,
      HDR_BLUR_RADIUS = 0x1,
      HDR_BLUR_PASSES = 0x2,
      HDR_EMISSIVE_MULT = 0x3,
      HDR_TARGET_LUM = 0x4,
      HDR_UPPER_LUM_CLAMP = 0x5,
      HDR_BRIGHT_SCALE = 0x6,
      HDR_BRIGHT_CLAMP = 0x7,
      HDR_LUM_RAMP_NO_TEX = 0x8,
      HDR_LUM_RAMP_MIN = 0x9,
      HDR_LUM_RAMP_MAX = 0xA,
      HDR_SUNLIGHT_DIMMER = 0xB,
      HDR_GRASS_DIMMER = 0xC,
      HDR_TREE_DIMMER = 0xD,
      HDR_COUNT = 0xE,
    };

    class WeatherSound
    {
      public:
        std::uint32_t uiSoundFormID;
        SoundType eType;
    };

    class WeatherSoundList : BSSimpleList<WeatherSound *>{};

    TESTexture1024 cloudTexture[4];
    std::uint8_t ucCloudLayerSpeed[4];
    std::uint32_t uiCloudColorData[4][6];
    TESModel precipNIF;
    std::uint8_t ucWeatherData[15];
    float fFogData[6];
    std::uint32_t uiColorData[10][6];
    TESWeather::WeatherSoundList soundList;
    float fHDRData[14];
    ImageSpaceParameterData pImageSpaceParameterMods[2];
    std::int32_t iNumCloudLayers;
};

static_assert(sizeof(TESWeather) == 0x36C, "TESWeather has wrong size");
