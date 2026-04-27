#pragma once
#include <cstdint>
#include "Bethesda/TESCondition.hpp"
#include "Bethesda/TeleportPath.hpp"

namespace CommonLib {

  class TESObjectREFR;

  class TESQuestTarget
  {
    public:

      std::uint8_t cFlags;
      TESCondition objConditions;
      TESObjectREFR *m_pTargetRef;
      TeleportPath m_TargetPath;
  };

  static_assert(sizeof(TESQuestTarget) == 0x48, "TESQuestTarget has wrong size");
  
} // namespace CommonLib
