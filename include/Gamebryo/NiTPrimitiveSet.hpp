#pragma once
#include <cstdint>
#include "Gamebryo/NiTSet.hpp"

namespace CommonLib {

  template <typename T>
  class NiTPrimitiveSet : public NiTSet<T, NiTMallocInterface<T>>
  {
    public:
      NiTPrimitiveSet();
      ~NiTPrimitiveSet();
  };

  static_assert(sizeof(NiTPrimitiveSet<std::int32_t>) == 0xC, "NiTPrimitiveSet has wrong size");
  
} // namespace CommonLib
