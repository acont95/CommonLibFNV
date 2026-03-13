#pragma once
#include "Gamebryo/NiTPointerListBase.hpp"
#include "Gamebryo/NiTPointerAllocator.hpp"

template <typename T>
class NiTPointerList : NiTPointerListBase<NiTPointerAllocator<size_t>, T>
{
  public:
    NiTPointerList();
    ~NiTPointerList();
};

static_assert(sizeof(NiTPointerList<void*>) == 0xC, "NiTPointerList has wrong size");
