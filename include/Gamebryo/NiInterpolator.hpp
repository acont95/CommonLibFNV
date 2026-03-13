#pragma once
#include "Gamebryo/NiObject.hpp"

class NiInterpolator : NiObject
{
  public:
    NiInterpolator();
    ~NiInterpolator();

    float m_fLastTime;
};

static_assert(sizeof(NiInterpolator) == 0xC, "NiInterpolator has wrong size");
