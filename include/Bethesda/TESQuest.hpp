#pragma once
#include <cstdint>
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
    std::uint8_t ucFlags;
    std::uint8_t ucPriority;
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
    std::uint8_t cCurrentStage;
    BSStringT<char> cFormEditorID;
};

static_assert(sizeof(TESQuest) == 0x6C, "TESQuest has wrong size");
