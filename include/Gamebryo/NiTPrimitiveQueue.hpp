#pragma once
#include <cstdint>
#include "Gamebryo/NiTQueue.hpp"
#include "Gamebryo/NiTMallocInterface.hpp"

namespace CommonLib {

  class NiTask;

  template <typename T>
  class NiTPrimitiveQueue : public NiTQueue<T, NiTMallocInterface<T>> {};

  static_assert(sizeof(NiTPrimitiveQueue<void*>) == 0x10, "NiTPrimitiveQueue has wrong size");
  
} // namespace CommonLib
