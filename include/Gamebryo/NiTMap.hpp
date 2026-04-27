#pragma once
#include "Gamebryo/NiTMapBase.hpp"

namespace CommonLib {

  template <typename Key, typename Value>
  class NiTMap : public NiTMapBase<DFALL<NiTMapItem<Key, Value>>, Key, Value>
  {
    public:

  };

  static_assert(sizeof(NiTMap<void*, void*>) == 0x10, "NiTMap has wrong size");
  
} // namespace CommonLib
