#pragma once
#include "Gamebryo/NiTAbstractPoolAllocator.hpp"

template <typename T>
class NiTPointerAllocator : NiTAbstractPoolAllocator<T>
{
  public:
    NiTPointerAllocator();
    ~NiTPointerAllocator();
};

static_assert(sizeof(NiTPointerAllocator<unsigned int>) == 0x1, "NiTPointerAllocator has wrong size");
