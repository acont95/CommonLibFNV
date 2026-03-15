#pragma once
#include "Bethesda/BSOcclusionQuery.hpp"
#include "Gamebryo/NiPoint3.hpp"

class ReferenceVolume
{
  public:
    ReferenceVolume();
    ~ReferenceVolume();

    NiPoint3 Center;
    float fRadius;
    unsigned int uiReferenceID;
    BSOcclusionQuery *pOcclusionQuery;
    bool bOccluded;
    bool bWaiting;
    bool bPerformTest;
    unsigned int uiPixelCount;
};

static_assert(sizeof(ReferenceVolume) == 0x20);
