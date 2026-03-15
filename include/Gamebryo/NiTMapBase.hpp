#pragma once
#include <cstdint>
#include "Bethesda/TESForm.hpp"
#include "Gamebryo/NiTPointerAllocator.hpp"
#include "Gamebryo/NiMemObject.hpp"
#include "Gamebryo/NiTMapItem.hpp"

template <class Allocator, typename Key, typename Value>
class NiTMapBase : NiMemObject
{
  public:
    NiTMapBase();
    virtual ~NiTMapBase();

    struct AntiBloatAllocator : Allocator
    {
      std::uint32_t m_uiCount;
    };

    std::uint32_t m_uiHashSize;
    NiTMapItem<std::uint32_t, TESForm*>** m_ppkHashTable;
    AntiBloatAllocator m_kAllocator;
};

static_assert(sizeof(NiTMapBase<NiTDefaultAllocator<void*>, void*, void*>) == 0x10, "NiTMapBase has wrong size");  
