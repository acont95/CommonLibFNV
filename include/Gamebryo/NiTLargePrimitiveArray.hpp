#pragma once
#include "Gamebryo/NiTLargeArray.hpp"

namespace CommonLib {

  template <typename T>
  class NiTLargePrimitiveArray : public NiTLargeArray<T, NiTMallocInterface<T>>
  {
    public:
      NiTLargePrimitiveArray();
      virtual ~NiTLargePrimitiveArray();

  };

  static_assert(sizeof(NiTLargePrimitiveArray<void*>) == 0x18, "NiTLargePrimitiveArray has wrong size");
  
} // namespace CommonLib
