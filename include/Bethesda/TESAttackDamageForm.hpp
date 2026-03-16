#pragma once
#include <cstdint>
#include "Bethesda/BaseFormComponent.hpp"

class TESAttackDamageForm : public BaseFormComponent
{
  public:
    TESAttackDamageForm();
    virtual ~TESAttackDamageForm();

    std::uint16_t sAttackDamage;
};

static_assert(sizeof(TESAttackDamageForm) == 0x8, "TESAttackDamageForm has wrong size");
