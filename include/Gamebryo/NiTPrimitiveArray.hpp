#pragma once
#include "Gamebryo/NiTArray.hpp"
#include "Gamebryo/NiTMallocInterface.hpp"

template <typename T>
class NiTPrimitiveArray : public NiTArray<T, NiTMallocInterface<T>>
{
  public:
    NiTPrimitiveArray();
    ~NiTPrimitiveArray();
};

static_assert(sizeof(NiTPrimitiveArray<void *>) == 0x10, "NiTPrimitiveArray has wrong size");
