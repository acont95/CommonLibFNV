#pragma once
#include <cstdint>

namespace CommonLib {

  class BSSoundHandle
  {
    public:
      BSSoundHandle();
      ~BSSoundHandle();

      enum ASSUMED_STATE
      {
        ASSUMED_STATE_INITIALIZED = 0x0,
        ASSUMED_STATE_PLAYING = 0x1,
        ASSUMED_STATE_STOPPED = 0x2,
        ASSUMED_STATE_PAUSED = 0x3,
      };

      std::uint32_t iSoundID;
      bool bAssumeSuccess;
      ASSUMED_STATE eState;
  };

  static_assert(sizeof(BSSoundHandle) == 0xC, "BSSoundHandle has wrong size");
  
} // namespace CommonLib
