#pragma once
#include "Gamebryo/NiTArray.hpp"
#include "Gamebryo/NiTMallocInterface.hpp"

namespace CommonLib {

  template <typename T>
  class NiTPrimitiveArray : public NiTArray<T, NiTMallocInterface<T>>
  {
    public:

  };

  static_assert(sizeof(NiTPrimitiveArray<void *>) == 0x10, "NiTPrimitiveArray has wrong size");
  
} // namespace CommonLib
