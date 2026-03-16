#pragma once
#include <cstdint>
#include "Bethesda/BSStringT.hpp"
#include "Bethesda/BSSimpleList.hpp"

namespace CommonLib {

  class TESQuest;
  class TESQuestTarget;

  enum QUEST_OBJECTIVE_STATE
  {
    QOS_DORMANT = 0x0,
    QOS_DISPLAYED = 0x1,
    QOS_COMPLETED = 0x2,
    QOS_COMPLETED_DISPLAYED = 0x3,
  };

  class BGSQuestObjective
  {
    public:
      BGSQuestObjective();
      virtual ~BGSQuestObjective();

      std::uint32_t iIndex;
      BSStringT<char> cDisplayText;
      TESQuest *pOwnerQuest;
      BSSimpleList<TESQuestTarget*> ListTargets;
      bool bInitialized;
      QUEST_OBJECTIVE_STATE eState;
  };

  static_assert(sizeof(BGSQuestObjective) == 0x24, "BGSQuestObjective has wrong size");
  
} // namespace CommonLib
