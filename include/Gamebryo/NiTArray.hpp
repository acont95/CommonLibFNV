#pragma once
#include <cstdint>
#include "Gamebryo/NiPointer.hpp"

template <typename T, typename TAllocator>
class NiTArray
{
  public:
    NiTArray();
    virtual ~NiTArray();

    T *m_pBase;
    std::uint16_t m_usMaxSize;
    std::uint16_t m_usSize;
    std::uint16_t m_usESize;
    std::uint16_t m_usGrowBy;
};

static_assert(sizeof(NiTArray<void*, void*>) == 0x10, "NiTArray has wrong size");
