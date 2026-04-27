#pragma once
#include "Bethesda/BSSemaphore.hpp"
#include "Bethesda/BSTCommonScrapHeapMessageQueue.hpp"

namespace CommonLib {

  class BSPackedTask;

  class BSPackedTaskQueue
  {
    public:

      BSTCommonScrapHeapMessageQueue<BSPackedTask> Queue;
      BSSemaphore InputSources;
      void (__cdecl *pUnpackFunc)(const BSPackedTask *);
      bool bProcessing;
  };

  static_assert(sizeof(BSPackedTaskQueue) == 0x28, "BSPackedTaskQueue has wrong size");
  
} // namespace CommonLib
