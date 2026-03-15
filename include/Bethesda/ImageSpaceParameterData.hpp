#pragma once
#include <cstdint>

class ImageSpaceParameterData
{
  public:
    ImageSpaceParameterData();
    ~ImageSpaceParameterData();

    float pfHDRData[15];
    float pfBloomData[3];
    float pfGetHitData[3];
    float pfNightEyeData[4];
    float pfCinematicData[12];
    std::uint32_t uiCinematicsEnabled;
};

static_assert(sizeof(ImageSpaceParameterData) == 0x98);
