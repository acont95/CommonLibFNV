#pragma once
#include "Gamebryo/NiMemObject.hpp"

template <typename T>
class NiTListItem : NiMemObject
{
  public:
    NiTListItem();
    ~NiTListItem();

    NiTListItem<T>* m_pkNext;
    NiTListItem<T>* m_pkPrev;
    T m_element;
};

static_assert(sizeof(NiTListItem<void*>) == 0xC, "NiTListItem has wrong size");
