#pragma once
#include "Bethesda/TESForm.hpp"
#include "Bethesda/TESScriptableForm.hpp"
#include "Bethesda/TESIcon.hpp"
#include "Bethesda/TESFullName.hpp"
#include "Bethesda/BSSimpleList.hpp"
#include "Bethesda/TESQuestStage.hpp"
#include "Bethesda/TESCondition.hpp"
#include "Bethesda/ScriptLocals.hpp"
#include "Bethesda/BGSQuestObjective.hpp"

class QUEST_DATA
{
  public:
    unsigned __int8 ucFlags;
    unsigned __int8 ucPriority;
    float fQuestDelayTime;
};

class TESQuest : TESForm, TESScriptableForm, TESIcon, TESFullName
{
  public:
    TESQuest();
    virtual ~TESQuest();

    QUEST_DATA data;
    BSSimpleList<TESQuestStage*> m_listStages;
    BSSimpleList<BGSQuestObjective*> m_listObjectives;
    TESCondition objConditions;
    ScriptLocals *pScriptLocals;
    unsigned __int8 cCurrentStage;
    BSStringT<char> cFormEditorID;
};

static_assert(sizeof(TESQuest) == 0x6C, "TESQuest has wrong size");
