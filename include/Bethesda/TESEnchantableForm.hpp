#pragma once
#include <cstdint>
#include "Bethesda/BaseFormComponent.hpp"
#include "Bethesda/TESForm.hpp"

class TESEnchantableForm : BaseFormComponent {
  public:
    TESEnchantableForm();
    ~TESEnchantableForm();

    EnchantmentItem* pFormEnchanting;
    std::uint16_t iAmountofEnchantment;
    MagicSystem::CastingType eCastingType;
};

static_assert(sizeof(TESEnchantableForm) == 0x10, "TESEnchantableForm has wrong size");
