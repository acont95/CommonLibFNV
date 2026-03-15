#pragma once
#include "Bethesda/Script.hpp"

class TESScriptableForm : BaseFormComponent
{
  public:
    TESScriptableForm();
    virtual ~TESScriptableForm();

    Script *pFormScript;
    bool bIsInitialized;
};

static_assert(sizeof(TESScriptableForm) == 0xC, "TESScriptableForm has wrong size");
