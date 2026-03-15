#pragma once
#include <cstdint>
#include "Gamebryo/NiTMallocInterface.hpp"

template <typename T, class TAllocator>
class NiTSet
{
  public:
    NiTSet();
    ~NiTSet();

    std::uint32_t* m_pBase;
    std::uint32_t m_uiAlloced;
    std::uint32_t m_uiUsed;
};

static_assert(sizeof(NiTSet<std::int32_t, NiTMallocInterface<std::int32_t>>) == 0xC, "NiTSet has wrong size");
