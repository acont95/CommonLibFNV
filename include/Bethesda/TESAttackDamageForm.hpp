#pragma once
#include "Bethesda/BaseFormComponent.hpp"

class TESAttackDamageForm : BaseFormComponent
{
  public:
    TESAttackDamageForm();
    virtual ~TESAttackDamageForm();

    unsigned __int16 sAttackDamage;
};

static_assert(sizeof(TESAttackDamageForm) == 0x8, "TESAttackDamageForm has wrong size");
