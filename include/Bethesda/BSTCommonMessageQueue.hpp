#pragma once


namespace CommonLib {

  template <typename T>
  class BSTCommonMessageQueue : public BSTMessageQueue<T>
  {
    public:
      BSTCommonMessageQueue();
      virtual ~BSTCommonMessageQueue();

      unsigned int uiLock;
  };

  static_assert(sizeof(BSTCommonMessageQueue<void*>) == 0x8, "BSTCommonMessageQueue has wrong size");
  
} // namespace CommonLib
