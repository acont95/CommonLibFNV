#pragma once
#include "Gamebryo/NiTArray.hpp"
#include "Gamebryo/NiTNewInterface.hpp"

template <typename T>
class NiTObjectArray : NiTArray<T, NiTNewInterface<T>>
{
  public:
    NiTObjectArray();
    ~NiTObjectArray();

};

static_assert(sizeof(NiTObjectArray<unsigned int>) == 0x10, "NiTObjectArray has wrong size");
