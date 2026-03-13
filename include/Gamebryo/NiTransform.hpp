#pragma once
#include "Gamebryo/NiMatrix3.hpp"
#include "Gamebryo/NiPoint3.hpp"

class NiTransform
{
  public:
    NiTransform();
    ~NiTransform();

    NiMatrix3 m_Rotate;
    NiPoint3 m_Translate;
    float m_fScale;
};

static_assert(sizeof(NiTransform) == 0x34, "NiTransform has wrong size");
