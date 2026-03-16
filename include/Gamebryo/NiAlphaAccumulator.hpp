#pragma once
#include "Gamebryo/NiBackToFrontAccumulator.hpp"

namespace CommonLib {

  class NiAlphaAccumulator : public NiBackToFrontAccumulator
  {
    public:
      NiAlphaAccumulator();
      virtual ~NiAlphaAccumulator();

      bool m_bObserveNoSortHint;
      bool m_bSortByClosestPoint;
      bool m_bInterfaceSort;
  };

  static_assert(sizeof(NiAlphaAccumulator) == 0x34, "NiAlphaAccumulator has wrong size");
  
} // namespace CommonLib
