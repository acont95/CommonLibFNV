#pragma once
#include "Gamebryo/NiTLargeArray.hpp"

template <typename T>
class NiTLargePrimitiveArray : NiTLargeArray<T, NiTMallocInterface<T>>
{
  public:
    NiTLargePrimitiveArray();
    virtual ~NiTLargePrimitiveArray();

};

static_assert(sizeof(NiTLargePrimitiveArray<void*>) == 0x18, "NiTLargePrimitiveArray has wrong size");