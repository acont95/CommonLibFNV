#pragma once
#include <cstdint>

namespace CommonLib {

  class BSSpinLock
  {
    public:

      volatile std::uint32_t uiOwningThread;
      std::uint32_t uiLockCount;
      std::uint32_t unk08[6];
  };

  static_assert(sizeof(BSSpinLock) == 0x20, "BSSpinLock has wrong size");
  
} // namespace CommonLib
