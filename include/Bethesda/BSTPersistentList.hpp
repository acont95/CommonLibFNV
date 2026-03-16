#pragma once
#include <cstdint>
#include "Gamebryo/NiTPointerAllocator.hpp"

class NiGeometry;

template <class TAllocator, typename T>
class BSTPersistentList
{
  public:
    BSTPersistentList();
    virtual ~BSTPersistentList();

    struct ListItem
    {
      ListItem *pNext;
      ListItem *pPrev;
      NiGeometry *tElement;
    };

    class AntiBloatAllocator : public TAllocator
    {
      std::uint32_t uiCount;
    };


    ListItem *pHead;
    ListItem *pTail;
    ListItem *pNextFreeItem;
    AntiBloatAllocator Allocator;
};

static_assert(sizeof(BSTPersistentList<NiTPointerAllocator<std::int32_t>, void*>) == 0x14, "BSTPersistentList has wrong size");
