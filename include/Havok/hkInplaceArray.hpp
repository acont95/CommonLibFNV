#pragma once
#include "Havok/hkArray.hpp"

namespace CommonLib {

  template <typename T, size_t TSize, typename TAllocator>
  class hkInplaceArray : public hkArray<T, TAllocator>
  {
    public:
      hkInplaceArray();
      ~hkInplaceArray();

      T m_storage[TSize];
  };

  static_assert(sizeof(hkInplaceArray<char, 128, void*>) == 0x8C, "hkInplaceArray has wrong size");
  
} // namespace CommonLib
