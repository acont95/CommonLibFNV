#pragma once
#include "Gamebryo/NiColorA.hpp"
#include "Gamebryo/NiAnimationKey.hpp"

class NiColorKey : public NiAnimationKey
{
  public:
    NiColorKey();
    ~NiColorKey();

    NiColorA m_Color;
};

static_assert(sizeof(NiColorKey) == 0x14, "NiColorKey has wrong size");
