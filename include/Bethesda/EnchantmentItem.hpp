#pragma once
#include <cstdint>
#include "Bethesda/MagicSystem.hpp"
#include "Bethesda/MagicItemForm.hpp"

class EnchantmentItem : MagicItemForm 
{
  public:
    EnchantmentItem();
    ~EnchantmentItem();

    struct EnchantmentItemData
    {
      MagicSystem::CastingType eCastingType;
      int iChargeOverride;
      int iCostOverride;
      std::uint8_t iFlags;
    };

    EnchantmentItemData data;
};  

static_assert(sizeof(EnchantmentItem) == 0x44, "EnchantmentItem has wrong size");
