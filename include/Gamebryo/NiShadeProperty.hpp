#pragma once
#include "Gamebryo/NiProperty.hpp"

class NiShadeProperty : public NiProperty
{
  public:
    NiShadeProperty();
    virtual ~NiShadeProperty();

    unsigned __int16 m_uFlags;
    int iShaderPropertyType;
};

static_assert(sizeof(NiShadeProperty) == 0x20, "NiShadeProperty has wrong size");
