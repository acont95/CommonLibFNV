#pragma once
#include "Gamebryo/NiTListItem.hpp"
#include "Gamebryo/NiNode.hpp"
#include "Gamebryo/NiMemObject.hpp"

template <class TAllocator, typename T>
class NiTListBase : NiMemObject
{
  public:
    NiTListBase();
    ~NiTListBase();

    class AntiBloatAllocator : TAllocator
    {
      unsigned int m_uiCount;
    };

    NiTListItem<T>* m_pkHead;
    NiTListItem<T>* m_pkTail;
    AntiBloatAllocator m_kAllocator;
};

static_assert(sizeof(NiTListBase<void*, void*>) == 0xC, "NiTListBase has wrong size");
