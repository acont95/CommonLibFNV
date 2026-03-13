#pragma once
#include "Gamebryo/NiPointer.hpp" 
#include "Gamebryo/NiProperty.hpp"

class NiPropertyState
{
  public:
    NiPropertyState();
    ~NiPropertyState();

    NiPointer<NiProperty> m_aspProps[7];
};

static_assert(sizeof(NiPropertyState) == 0x1C, "NiPropertyState has wrong size");
