#pragma once
#include "Gamebryo/NiMemObject.hpp"

template <typename Key, typename Value>
class NiTMapItem : NiMemObject
{
  public:
    NiTMapItem();
    ~NiTMapItem();

    NiTMapItem<Key ,Value> *m_pkNext;
    Key m_key;
    Value m_val;
};

static_assert(sizeof(NiTMapItem<void*, void*>) == 0xC, "NiTMapItem has wrong size");
