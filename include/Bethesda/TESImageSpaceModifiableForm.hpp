#pragma once
#include "Bethesda/BaseFormComponent.hpp"
#include "Bethesda/TESImageSpaceModifier.hpp"

class TESImageSpaceModifiableForm : BaseFormComponent
{
  public:
    TESImageSpaceModifiableForm();
    ~TESImageSpaceModifiableForm();

    TESImageSpaceModifier* pFormImageSpaceModifying;
};

static_assert(sizeof(TESImageSpaceModifiableForm) == 0x8, "TESImageSpaceModifiableForm has wrong size");
