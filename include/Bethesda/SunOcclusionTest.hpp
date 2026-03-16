#pragma once
#include <cstdint>

class BSOcclusionQuery;

class SunOcclusionTest
{
  public:
    SunOcclusionTest();
    ~SunOcclusionTest();

    BSOcclusionQuery* pOcclusionQuery;
    bool bWaiting;
    float fPercentOccluded;
    std::uint32_t uiPixelCount;
    std::uint32_t uiFrameCount;
};

static_assert(sizeof(SunOcclusionTest) == 0x14, "SunOcclusionTest has wrong size");
