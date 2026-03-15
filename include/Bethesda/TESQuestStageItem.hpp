#pragma once
#include "Bethesda/TESCondition.hpp"
#include "Bethesda/Script.hpp"
#include "Bethesda/TESQuest.hpp"
#include "Bethesda/Date.hpp"

struct QUEST_STAGE_ITEM_DATA
{
  unsigned __int8 iFlags;
};

class TESQuestStageItem
{
  public:
    TESQuestStageItem();
    ~TESQuestStageItem();

    QUEST_STAGE_ITEM_DATA m_Data;
    TESCondition objConditions;
    Script cResultScript;
    unsigned int m_fileOffset;
    unsigned __int8 ucIndex;
    bool m_bHasLogEntry;
    Date *m_pLogDate;
    TESQuest *m_pOwner;
    TESQuest *m_pNextQuest;
};

static_assert(sizeof(TESQuestStageItem) == 0x74, "TESQuestStageItem has wrong size");
