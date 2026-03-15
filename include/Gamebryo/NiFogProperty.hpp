#pragma once
#include <cstdint>
#include "Gamebryo/NiColor.hpp"
#include "Gamebryo/NiProperty.hpp"

class NiFogProperty : NiProperty
{
  public:
    NiFogProperty();
    virtual ~NiFogProperty();

    std::uint16_t m_uFlags;
    float m_fDepth;
    NiColor m_kColor;
};

static_assert(sizeof(NiFogProperty) == 0x2C, "NiFogProperty has wrong size");
