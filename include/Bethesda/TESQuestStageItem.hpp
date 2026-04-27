#pragma once
#include <cstdint>
#include "Bethesda/TESCondition.hpp"
#include "Bethesda/Script.hpp"

namespace CommonLib {

  class TESQuest;
  class Date;

  struct QUEST_STAGE_ITEM_DATA
  {
    std::uint8_t iFlags;
  };

  class TESQuestStageItem
  {
    public:

      QUEST_STAGE_ITEM_DATA m_Data;
      TESCondition objConditions;
      Script cResultScript;
      std::uint32_t m_fileOffset;
      std::uint8_t ucIndex;
      bool m_bHasLogEntry;
      Date *m_pLogDate;
      TESQuest *m_pOwner;
      TESQuest *m_pNextQuest;
  };

  static_assert(sizeof(TESQuestStageItem) == 0x74, "TESQuestStageItem has wrong size");
  
} // namespace CommonLib
