#pragma once
#include "Gamebryo/NiTMallocInterface.hpp"

template <typename T, class TAllocator>
class NiTSet
{
  public:
    NiTSet();
    ~NiTSet();

    unsigned int* m_pBase;
    unsigned int m_uiAlloced;
    unsigned int m_uiUsed;
};

static_assert(sizeof(NiTSet<int, NiTMallocInterface<int>>) == 0xC, "NiTSet has wrong size");
