#pragma once
#include "Gamebryo/NiTNewInterface.hpp"
#include "Gamebryo/NiTLargeArray.hpp"

template <typename T>
class NiTLargeObjectArray : public NiTLargeArray<T, NiTNewInterface<T>>
{
  public:
    NiTLargeObjectArray();
    virtual ~NiTLargeObjectArray();

};

static_assert(sizeof(NiTLargeObjectArray<void*>) == 0x18, "NiTLargeObjectArray has wrong size");
