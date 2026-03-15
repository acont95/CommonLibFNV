#pragma once
#include "Bethesda/BSOcclusionQuery.hpp"

class SunOcclusionTest
{
  public:
    SunOcclusionTest();
    ~SunOcclusionTest();

    BSOcclusionQuery* pOcclusionQuery;
    bool bWaiting;
    float fPercentOccluded;
    unsigned int uiPixelCount;
    unsigned int uiFrameCount;
};

static_assert(sizeof(SunOcclusionTest) == 0x14, "SunOcclusionTest has wrong size");
