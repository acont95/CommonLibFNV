#pragma once
#include <cstdint>
#include "Gamebryo/NiTMallocInterface.hpp"

template <typename T, typename TAllocator>
class NiTLargeArray
{
  public:
    NiTLargeArray();
    virtual ~NiTLargeArray();

    T* m_pBase;
    std::uint32_t m_uiMaxSize;
    std::uint32_t m_uiSize;
    std::uint32_t m_uiESize;
    std::uint32_t m_uiGrowBy;
};

static_assert(sizeof(NiTLargeArray<void*, NiTMallocInterface<void*>>) == 0x18, "NiTLargeArray has wrong size");
