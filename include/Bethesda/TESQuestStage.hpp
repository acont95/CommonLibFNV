#pragma once
#include <cstdint>
#include "Bethesda/BSSimpleList.hpp"

namespace CommonLib {

  class TESQuestStageItem;

  class QUEST_STAGE_DATA
  {
    public:
      std::uint8_t ucIndex;
      bool bIsDone;
  };

  class TESQuestStage
  {
    public:

      QUEST_STAGE_DATA m_Data;
      BSSimpleList<TESQuestStageItem*> listStageItems;
  };

  static_assert(sizeof(TESQuestStage) == 0xC, "TESQuestStage has wrong size");
  
} // namespace CommonLib
