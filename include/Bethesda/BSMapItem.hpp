#pragma once
#include <cstdint>
#include "Bethesda/ScrapHeap.hpp"

template <typename Key, typename Value>
class BSMapItem
{
  public:
    BSMapItem();
    ~BSMapItem();

    BSMapItem<Key, Value> *m_pkNext;
    std::uint32_t m_key;
    ScrapHeap *m_val;
};

static_assert(sizeof(BSMapItem<void*, void*>) == 0xC, "BSMapBase has wrong size");
