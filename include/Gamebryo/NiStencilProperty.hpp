#pragma once
#include <cstdint>
#include "Gamebryo/NiProperty.hpp"

class NiStencilProperty : NiProperty
{
  public:
    NiStencilProperty();
    ~NiStencilProperty();

    std::uint16_t m_uFlags;
    std::uint32_t m_uiRef;
    std::uint32_t m_uiMask;
};

static_assert(sizeof(NiStencilProperty) == 0x24, "NiStencilProperty has wrong size");
