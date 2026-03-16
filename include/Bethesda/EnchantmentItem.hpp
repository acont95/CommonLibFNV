#pragma once
#include <cstdint>
#include "Bethesda/MagicItemForm.hpp"
#include "Bethesda/MagicSystem.hpp"

namespace CommonLib {

  class EnchantmentItem : public MagicItemForm 
  {
    public:
      EnchantmentItem();
      ~EnchantmentItem();

      struct EnchantmentItemData
      {
        MagicSystem::CastingType eCastingType;
        std::int32_t iChargeOverride;
        std::int32_t iCostOverride;
        std::uint8_t iFlags;
      };

      EnchantmentItemData data;
  };  

  static_assert(sizeof(EnchantmentItem) == 0x44, "EnchantmentItem has wrong size");
  
} // namespace CommonLib
