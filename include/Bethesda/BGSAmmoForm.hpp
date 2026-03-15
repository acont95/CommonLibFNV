#pragma once
#include "Bethesda/BaseFormComponent.hpp"
#include "Bethesda/TESForm.hpp"

class BGSAmmoForm : BaseFormComponent
{
  public:
    BGSAmmoForm();
    virtual ~BGSAmmoForm();

    TESForm *pFormAmmo;
};

static_assert(sizeof(BGSAmmoForm) == 0x8, "BGSAmmoForm has wrong size");
