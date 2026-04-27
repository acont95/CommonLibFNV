#pragma once

namespace CommonLib {

  template <typename T>
  class BSSimpleList {
    public:

      T m_item;
      BSSimpleList<T>* m_pkNext;
  };

  static_assert(sizeof(BSSimpleList<void*>) == 0x8, "BSSimpleList has wrong size");
  
} // namespace CommonLib
