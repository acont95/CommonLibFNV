#pragma once
#include "Gamebryo/NiTListBase.hpp"

template <typename TAllocator, typename T>
class NiTPointerListBase : NiTListBase<TAllocator, T>
{
  public:
    NiTPointerListBase();
    ~NiTPointerListBase();
};

static_assert(sizeof(NiTPointerListBase<void*, void*>) == 0xC, "NiTPointerListBase has wrong size");
