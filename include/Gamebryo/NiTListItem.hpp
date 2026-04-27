#pragma once
#include "Gamebryo/NiMemObject.hpp"

namespace CommonLib {

  template <typename T>
  class NiTListItem : public NiMemObject
  {
    public:

      NiTListItem<T>* m_pkNext;
      NiTListItem<T>* m_pkPrev;
      T m_element;
  };

  static_assert(sizeof(NiTListItem<void*>) == 0xC, "NiTListItem has wrong size");
  
} // namespace CommonLib
