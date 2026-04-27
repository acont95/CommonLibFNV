#pragma once
#include <cstdint>
#include "Gamebryo/NiObject.hpp"
#include "Gamebryo/NiPointer.hpp"

namespace CommonLib {

  class NiObjectNET;

  class NiTimeController : public NiObject
  {
    public:

      std::uint16_t m_uFlags;
      float m_fFrequency;
      float m_fPhase;
      float m_fLoKeyTime;
      float m_fHiKeyTime;
      float m_fStartTime;
      float m_fLastTime;
      float m_fWeightedLastTime;
      float m_fScaledTime;
      NiObjectNET *m_pkTarget;
      NiPointer<NiTimeController> m_spNext;
  };

  static_assert(sizeof(NiTimeController) == 0x34, "NiTimeController has wrong size");
  
} // namespace CommonLib
