#pragma once
#include "Gamebryo/NiGeometry.hpp"
#include "Gamebryo/NiTPointerAllocator.hpp"

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

    class AntiBloatAllocator : TAllocator
    {
      unsigned int uiCount;
    };


    ListItem *pHead;
    ListItem *pTail;
    ListItem *pNextFreeItem;
    AntiBloatAllocator Allocator;
};

static_assert(sizeof(BSTPersistentList<NiTPointerAllocator<int>, void*>) == 0x14, "BSTPersistentList has wrong size");
