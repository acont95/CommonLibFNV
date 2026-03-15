#pragma once
#include <cstdint>
#include "Gamebryo/NiTListItem.hpp"
#include "Gamebryo/NiNode.hpp"
#include "Gamebryo/NiMemObject.hpp"
#include "Gamebryo/NiTDefaultAllocator.hpp"

template <class TAllocator, typename T>
class NiTListBase : NiMemObject
{
  public:
    NiTListBase();
    ~NiTListBase();

    class AntiBloatAllocator : TAllocator
    {
      std::uint32_t m_uiCount;
    };

    NiTListItem<T>* m_pkHead;
    NiTListItem<T>* m_pkTail;
    AntiBloatAllocator m_kAllocator;
};

static_assert(sizeof(NiTListBase<NiTDefaultAllocator<void*>, void*>) == 0xC, "NiTListBase has wrong size");
