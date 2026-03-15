#pragma once
#include "Bethesda/BSMapItem.hpp"

template <typename Key, typename Value>
class BSMapBase
{
  public:
    BSMapBase();
    virtual ~BSMapBase();

    unsigned int m_uiHashSize;
    BSMapItem<Key, Value> **m_ppkHashTable;
    unsigned int m_uiCount;
};

static_assert(sizeof(BSMapBase<void*, void*>) == 0x10, "BSMapBase has wrong size");
