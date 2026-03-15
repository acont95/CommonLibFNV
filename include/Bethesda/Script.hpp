#pragma once
#include "Bethesda/TESQuest.hpp"
#include "Bethesda/BSSimpleList.hpp"
#include "Bethesda/ScriptVariable.hpp"
#include "Bethesda/TESForm.hpp"
#include "Bethesda/BSStringT.hpp"

struct SCRIPT_HEADER
{
  unsigned int variableCount;
  unsigned int refObjectCount;
  unsigned int dataSize;
  unsigned int m_uiLastID;
  bool bIsQuestScript;
  bool bIsMagicEffectScript;
  bool bIsCompiled;
};

class SCRIPT_REFERENCED_OBJECT
{
  public:
    BSStringT<char> cEditorID;
    TESForm* pForm;
    unsigned int uiVariableID;
};

class Script : TESForm
{
  public:
    Script();
    ~Script();

    SCRIPT_HEADER m_header;
    char *m_text;
    char *m_data;
    float fProfilerTimer;
    float fQuestScriptDelay;
    float fQuestScriptGetSecondsBuffer;
    TESQuest *pOwnerQuest;
    BSSimpleList<SCRIPT_REFERENCED_OBJECT *> listRefObjects;
    BSSimpleList<ScriptVariable *> listVariables;
};

static_assert(sizeof(Script) == 0x54, "Script has wrong size");
