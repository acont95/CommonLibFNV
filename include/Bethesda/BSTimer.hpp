#pragma once
#include <cstdint>

namespace CommonLib {

  class BSTimer
  {
    public:
      static BSTimer* GetAppTimerSingleton();

      std::uint8_t cDisableCounter;
      float fClamp;
      float fClampRemainder;
      float fDelta;
      float fDeltaUnmodified;
      unsigned int iLastTime;
      unsigned int iFirstTime;
      bool bUseGlobalTimeMultiplierTarget;
      bool bZeroDelta;
  };

  static_assert(sizeof(BSTimer) == 0x20, "BSTimer has wrong size");
  
} // namespace CommonLib
