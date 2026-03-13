#pragma once
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
      unsigned int m_uiCount;
    };

    unsigned int m_uiHashSize;
    NiTMapItem<unsigned int, TESForm*>** m_ppkHashTable;
    AntiBloatAllocator m_kAllocator;
};

static_assert(sizeof(NiTMapBase<void*, void*, void*>) == 0x10, "NiTMapBase has wrong size");  
