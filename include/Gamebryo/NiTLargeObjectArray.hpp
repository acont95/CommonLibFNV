#pragma once
#include "Bethesda/BSStream.hpp"
#include "Gamebryo/NiTNewInterface.hpp"

template <typename T>
class NiTLargeObjectArray : NiTLargeArray<T, NiTNewInterface<T>>
{
  public:
    NiTLargeObjectArray();
    virtual ~NiTLargeObjectArray();

};

static_assert(sizeof(NiTLargeObjectArray<void*>) == 0x18, "NiTLargeObjectArray has wrong size");
