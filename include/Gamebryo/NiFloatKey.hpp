#pragma once
#include "Gamebryo/NiAnimationKey.hpp"

class NiFloatKey : public NiAnimationKey
{
  public:
    NiFloatKey();
    ~NiFloatKey();

    float m_fValue;
};

static_assert(sizeof(NiFloatKey) == 0x8, "NiFloatKey has wrong size");
