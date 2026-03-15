#pragma once
#include <cstdint>
#include "Gamebryo/NiGeometry.hpp"

class NiVisibleArray
{
  public:
    NiVisibleArray();
    ~NiVisibleArray();

    NiGeometry** m_ppkArray;
    std::uint32_t m_uiCurrentSize;
    std::uint32_t m_uiAllocatedSize;
    std::uint32_t m_uiGrowBy;
};

static_assert(sizeof(NiVisibleArray) == 0x10, "NiVisibleArray has wrong size");
