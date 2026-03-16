#pragma once
#include <cstdint>
#include "Gamebryo/NiKeyBasedInterpolator.hpp"
#include "Gamebryo/NiColorData.hpp"
#include "Gamebryo/NiColorA.hpp"
#include "Gamebryo/NiPointer.hpp"

namespace CommonLib {

  class NiColorInterpolator : public NiKeyBasedInterpolator
  {
    public:
      NiColorInterpolator();
      ~NiColorInterpolator();

      NiColorA m_kColorValue;
      NiPointer<NiColorData> m_spColorData;
      std::uint32_t m_uiLastIdx;
  }; 

  static_assert(sizeof(NiColorInterpolator) == 0x24, "NiColorInterpolator has wrong size");
  
} // namespace CommonLib
