#pragma once
#include "Havok/hkArrayBase.hpp"

template <typename T, typename TAllocator>
class hkArray : hkArrayBase<T>
{
  public:
    hkArray();
    ~hkArray();
};

static_assert(sizeof(hkArray<void*, void*>) == 0xC, "hkArray has wrong size");
