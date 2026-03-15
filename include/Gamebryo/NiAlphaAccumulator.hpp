#pragma once
#include "Gamebryo/NiBackToFrontAccumulator.hpp"

class NiAlphaAccumulator : NiBackToFrontAccumulator
{
  public:
    NiAlphaAccumulator();
    virtual ~NiAlphaAccumulator();

    bool m_bObserveNoSortHint;
    bool m_bSortByClosestPoint;
    bool m_bInterfaceSort;
};

static_assert(sizeof(NiAlphaAccumulator) == 0x34, "NiAlphaAccumulator has wrong size");
