#pragma once
#include <cstdint>

template <typename Key, typename Value>
class BSMapItem;

template <typename Key, typename Value>
class BSMapBase
{
  public:
    BSMapBase();
    virtual ~BSMapBase();

    std::uint32_t m_uiHashSize;
    BSMapItem<Key, Value> **m_ppkHashTable;
    std::uint32_t m_uiCount;
};

static_assert(sizeof(BSMapBase<void*, void*>) == 0x10, "BSMapBase has wrong size");
