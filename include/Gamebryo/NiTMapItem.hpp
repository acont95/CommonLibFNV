#pragma once
#include "Gamebryo/NiMemObject.hpp"

namespace CommonLib {

  template <typename Key, typename Value>
  class NiTMapItem : public NiMemObject
  {
    public:

      NiTMapItem<Key ,Value> *m_pkNext;
      Key m_key;
      Value m_val;
  };

  static_assert(sizeof(NiTMapItem<void*, void*>) == 0xC, "NiTMapItem has wrong size");
  
} // namespace CommonLib
