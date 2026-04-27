#pragma once
#include <cstdint>
#include "Gamebryo/NiFloatData.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiKeyBasedInterpolator.hpp"

namespace CommonLib {

  class NiFloatInterpolator : public NiKeyBasedInterpolator
  {
    public:

      float m_fFloatValue;
      NiPointer<NiFloatData> m_spFloatData;
      std::uint32_t m_uiLastIdx;
  };

  static_assert(sizeof(NiFloatInterpolator) == 0x18, "NiFloatInterpolator has wrong size");
  
} // namespace CommonLib
