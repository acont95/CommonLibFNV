#pragma once
#include "Gamebryo/NiDynamicEffect.hpp"
#include "Gamebryo/NiColor.hpp"

namespace CommonLib {

  class NiLight : public NiDynamicEffect
  {
    public:
      NiLight();
      ~NiLight();

      float m_fDimmer;
      NiColor m_kAmb;
      NiColor m_kDiff;
      NiColor m_kSpec;
      void* m_pvRendererData;
  };

  static_assert(sizeof(NiLight) == 0xF0, "NiLight has wrong size");
  
} // namespace CommonLib
