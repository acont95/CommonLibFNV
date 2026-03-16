#pragma once
#include <cstdint>
#include "Bethesda/TESScriptableForm.hpp"
#include "Bethesda/TESIcon.hpp"
#include "Bethesda/TESFullName.hpp"
#include "Bethesda/TESForm.hpp"
#include "Bethesda/TESCondition.hpp"
#include "Bethesda/ScriptLocals.hpp"

namespace CommonLib {

  class TESQuestStage;
  class BGSQuestObjective;

  class QUEST_DATA
  {
    public:
      std::uint8_t ucFlags;
      std::uint8_t ucPriority;
      float fQuestDelayTime;
  };

  class TESQuest : public TESForm, public TESScriptableForm, public TESIcon, public TESFullName
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
  
} // namespace CommonLib
