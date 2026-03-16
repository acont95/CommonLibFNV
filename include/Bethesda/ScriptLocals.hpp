#pragma once
#include <cstdint>

namespace CommonLib {

  class TESForm;
  class Script;
  template <typename T>
  class BSSimpleList;

  class SCRIPT_LOCAL
  {
    public:
      unsigned int uiID;
      double fValue;
      bool bIsInteger;
  };

  struct SCRIPT_EFFECT_DATA
  {
    bool m_bScriptEffectStart;
    bool m_bScriptEffectFinish;
    float m_fSecondsElapsed;
  };

  struct ACTION_OBJECT
  {
    TESForm *pForm;
    std::uint32_t iFlags;
  };


  class ScriptLocals
  {
    public:
      ScriptLocals();
      ~ScriptLocals();

      Script *m_pMasterScript;
      char m_cFlags;
      BSSimpleList<ACTION_OBJECT *> *m_pActionList;
      BSSimpleList<SCRIPT_LOCAL *> *m_pLocalList;
      SCRIPT_EFFECT_DATA *m_pScriptEffectData;
  };

  static_assert(sizeof(ScriptLocals) == 0x14, "ScriptLocals has wrong size");
  
} // namespace CommonLib
