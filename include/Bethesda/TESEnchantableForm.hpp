#pragma once
#include <cstdint>
#include "Bethesda/BaseFormComponent.hpp"
#include "Bethesda/MagicSystem.hpp"

namespace CommonLib {

  class EnchantmentItem;

  class TESEnchantableForm : public BaseFormComponent {
    public:

      EnchantmentItem* pFormEnchanting;
      std::uint16_t iAmountofEnchantment;
      MagicSystem::CastingType eCastingType;
  };

  static_assert(sizeof(TESEnchantableForm) == 0x10, "TESEnchantableForm has wrong size");
    
} // namespace CommonLib
