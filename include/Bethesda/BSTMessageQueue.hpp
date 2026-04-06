#pragma once

namespace CommonLib {

  template <typename T>
  class BSTMessageQueue
  {
    public:
      BSTMessageQueue();
      virtual ~BSTMessageQueue();
  };

  static_assert(sizeof(BSTMessageQueue<void*>) == 0x4, "BSTMessageQueue has wrong size");
  
} // namespace CommonLib
