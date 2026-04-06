#pragma once
#include "Bethesda/BSTCommonMessageQueue.hpp"
#include "Bethesda/BSTCommonScrapHeapMessageQueue.hpp"

namespace CommonLib {

  class ScrapHeap;
  template <typename T>
  class BSScrapHeapQueueElem;

  template <typename T>
  class BSTCommonScrapHeapMessageQueue : public BSTCommonMessageQueue<T>
  {
    public:
      BSTCommonScrapHeapMessageQueue();
      virtual ~BSTCommonScrapHeapMessageQueue();

      ScrapHeap* pScrapHeap;
      BSScrapHeapQueueElem<T> *pHead;
      BSScrapHeapQueueElem<T> **ppTail;
  };

  static_assert(sizeof(BSTCommonScrapHeapMessageQueue<void*>) == 0x14, "BSTCommonScrapHeapMessageQueue has wrong size");
  
} // namespace CommonLib
