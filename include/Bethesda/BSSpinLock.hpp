#pragma once
#include <cstdint>

namespace CommonLib {

  class BSSpinLock
  {
    public:
      BSSpinLock();
      ~BSSpinLock();

      volatile std::uint32_t uiOwningThread;
      std::uint32_t uiLockCount;
  };

  static_assert(sizeof(BSSpinLock) == 0x8, "BSSpinLock has wrong size");
  
} // namespace CommonLib
