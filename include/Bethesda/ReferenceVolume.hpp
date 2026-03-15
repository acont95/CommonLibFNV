#pragma once
#include <cstdint>
#include "Bethesda/BSOcclusionQuery.hpp"
#include "Gamebryo/NiPoint3.hpp"

class ReferenceVolume
{
  public:
    ReferenceVolume();
    ~ReferenceVolume();

    NiPoint3 Center;
    float fRadius;
    std::uint32_t uiReferenceID;
    BSOcclusionQuery *pOcclusionQuery;
    bool bOccluded;
    bool bWaiting;
    bool bPerformTest;
    std::uint32_t uiPixelCount;
};

static_assert(sizeof(ReferenceVolume) == 0x20);
