#pragma once
#include "Bethesda/BSStringT.hpp"
#include "Bethesda/TESQuest.hpp"
#include "Bethesda/BSSimpleList.hpp"
#include "Bethesda/TESQuestTarget.hpp"

enum QUEST_OBJECTIVE_STATE : __int32
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

    unsigned int iIndex;
    BSStringT<char> cDisplayText;
    TESQuest *pOwnerQuest;
    BSSimpleList<TESQuestTarget*> ListTargets;
    bool bInitialized;
    QUEST_OBJECTIVE_STATE eState;
};

static_assert(sizeof(BGSQuestObjective) == 0x24, "BGSQuestObjective has wrong size");
