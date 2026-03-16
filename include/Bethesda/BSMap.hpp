#pragma once
#include "Bethesda/BSMapBase.hpp"

namespace CommonLib {

  template <typename Key, typename Value>
  class BSMap : public BSMapBase<Key, Value>
  {
    public:
      BSMap();
      virtual ~BSMap();
  };

  static_assert(sizeof(BSMap<void*, void*>) == 0x10, "BSMap has wrong size");
  
} // namespace CommonLib
