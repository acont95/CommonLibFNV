#pragma once
#include "Gamebryo/NiAccumulator.hpp"
#include "Gamebryo/NiGeometry.hpp"

class NiBackToFrontAccumulator : NiAccumulator
{
  public:
    NiBackToFrontAccumulator();
    virtual ~NiBackToFrontAccumulator();

    NiTPointerList<NiGeometry *> m_kItems;
    NiTPointerList<NiGeometry *> *m_kItemsToSortAndRender;
    int m_iNumItems;
    int m_iMaxItems;
    NiGeometry **m_ppkItems;
    float *m_pfDepths;
    int m_iCurrItem;
};

static_assert(sizeof(NiBackToFrontAccumulator) == 0x30, "NiBackToFrontAccumulator has wrong size");
