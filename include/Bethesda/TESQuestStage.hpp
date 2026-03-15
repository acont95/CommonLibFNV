#pragma once
#include "Bethesda/BSSimpleList.hpp"
#include "Bethesda/TESQuestStageItem.hpp"

class QUEST_STAGE_DATA
{
  public:
    unsigned __int8 ucIndex;
    bool bIsDone;
};

class TESQuestStage
{
  public:
    TESQuestStage();
    ~TESQuestStage();

    QUEST_STAGE_DATA m_Data;
    BSSimpleList<TESQuestStageItem*> listStageItems;
};

static_assert(sizeof(TESQuestStage) == 0xC, "TESQuestStage has wrong size");
