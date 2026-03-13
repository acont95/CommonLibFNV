#pragma once
#include "Gamebryo/NiTMapBase.hpp"
#include "Gamebryo/NiTDefaultAllocator.hpp"

template <typename Key, typename Value>
class NiTMap : NiTMapBase<DFALL<NiTMapItem<Key, Value>>, Key, Value>
{
  public:
    NiTMap();
    ~NiTMap();
};

static_assert(sizeof(NiTMap<void*, void*>) == 0x10, "NiTMap has wrong size");
