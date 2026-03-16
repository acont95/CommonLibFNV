#pragma once
#include "Bethesda/BaseFormComponent.hpp"

class Script;

class TESScriptableForm : public BaseFormComponent
{
  public:
    TESScriptableForm();
    virtual ~TESScriptableForm();

    Script *pFormScript;
    bool bIsInitialized;
};

static_assert(sizeof(TESScriptableForm) == 0xC, "TESScriptableForm has wrong size");
