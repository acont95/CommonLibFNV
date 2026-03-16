#pragma once
#include "Havok/hkArrayBase.hpp"

namespace CommonLib {

  template <typename T, typename TAllocator>
  class hkArray : public hkArrayBase<T>
  {
    public:
      hkArray();
      ~hkArray();
  };

  static_assert(sizeof(hkArray<void*, void*>) == 0xC, "hkArray has wrong size");
  
} // namespace CommonLib
