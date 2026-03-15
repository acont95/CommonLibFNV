#pragma once
#include "Gamebryo/NiTMallocInterface.hpp"
#include "Gamebryo/NiTSet.hpp"

template <typename T>
class NiTPrimitiveSet : NiTSet<T, NiTMallocInterface<T>>
{
  public:
    NiTPrimitiveSet();
    ~NiTPrimitiveSet();
};

static_assert(sizeof(NiTPrimitiveSet<int>) == 0xC, "NiTPrimitiveSet has wrong size");
