#pragma once
#include "Gamebryo/NiTMallocInterface.hpp"

template <typename T, typename TAllocator>
class NiTLargeArray
{
  public:
    NiTLargeArray();
    virtual ~NiTLargeArray();

    T* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
};

static_assert(sizeof(NiTLargeArray<void*, NiTMallocInterface<void*>>) == 0x18, "NiTLargeArray has wrong size");
