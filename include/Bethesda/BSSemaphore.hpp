#pragma once
#include <cstdint>

namespace CommonLib {

  class BSPackedTask;

  class BSSemaphore
  {
    public:

      volatile std::int32_t iCount;
      void *hSemaphore;
      std::int32_t iMaxCount;
  };

  static_assert(sizeof(BSSemaphore) == 0xC, "BSSemaphore has wrong size");
  
} // namespace CommonLib
