#pragma once
#include "Gamebryo/NiGeometry.hpp"

class NiVisibleArray
{
  public:
    NiVisibleArray();
    ~NiVisibleArray();

    NiGeometry** m_ppkArray;
    unsigned int m_uiCurrentSize;
    unsigned int m_uiAllocatedSize;
    unsigned int m_uiGrowBy;
};

static_assert(sizeof(NiVisibleArray) == 0x10, "NiVisibleArray has wrong size");
