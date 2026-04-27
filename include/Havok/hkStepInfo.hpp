#pragma once
#include "Havok/hkPadSpu.hpp"

namespace CommonLib {

  class hkStepInfo
  {
    public:

      hkPadSpu<float> m_startTime;
      hkPadSpu<float> m_endTime;
      hkPadSpu<float> m_deltaTime;
      hkPadSpu<float> m_invDeltaTime;
  };

  static_assert(sizeof(hkStepInfo) == 0x10, "hkStepInfo has wrong size");
  
} // namespace CommonLib
