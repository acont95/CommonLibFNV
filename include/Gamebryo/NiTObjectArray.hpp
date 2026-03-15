#pragma once
#include <cstdint>
#include "Gamebryo/NiTArray.hpp"
#include "Gamebryo/NiTNewInterface.hpp"

template <typename T>
class NiTObjectArray : NiTArray<T, NiTNewInterface<T>>
{
  public:
    NiTObjectArray();
    ~NiTObjectArray();

};

static_assert(sizeof(NiTObjectArray<std::uint32_t>) == 0x10, "NiTObjectArray has wrong size");
