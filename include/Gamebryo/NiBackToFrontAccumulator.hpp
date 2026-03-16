#pragma once
#include <cstdint>
#include "Gamebryo/NiAccumulator.hpp"
#include "Gamebryo/NiTPointerList.hpp"

namespace CommonLib {

  class NiGeometry;

  class NiBackToFrontAccumulator : public NiAccumulator
  {
    public:
      NiBackToFrontAccumulator();
      virtual ~NiBackToFrontAccumulator();

      NiTPointerList<NiGeometry *> m_kItems;
      NiTPointerList<NiGeometry *> *m_kItemsToSortAndRender;
      std::int32_t m_iNumItems;
      std::int32_t m_iMaxItems;
      NiGeometry **m_ppkItems;
      float *m_pfDepths;
      std::int32_t m_iCurrItem;
  };

  static_assert(sizeof(NiBackToFrontAccumulator) == 0x30, "NiBackToFrontAccumulator has wrong size");
  
} // namespace CommonLib
