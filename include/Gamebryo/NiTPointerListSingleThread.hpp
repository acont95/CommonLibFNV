#pragma once
#include "Gamebryo/NiTPointerAllocator.hpp"
#include "Gamebryo/NiTPointerListBase.hpp"

template <typename T>
class NiTPointerListSingleThread : NiTPointerListBase<NiTPointerAllocator<unsigned int>, T>
{
  public:
    NiTPointerListSingleThread();
    ~NiTPointerListSingleThread();
};

static_assert(sizeof(NiTPointerListSingleThread<void*>) == 0xC, "NiTPointerListSingleThread has wrong size");
