#pragma once
#include <cstdint>
#include "Bethesda/MagicSystem.hpp"
#include "Bethesda/SkillLevel.hpp"

namespace CommonLib {

  class SpellItemData
  {
    public:
      SpellItemData();
      ~SpellItemData();

      MagicSystem::SpellType iSpellType;
      std::int32_t iCostOverride;
      SkillLevel::Value eLevelOverride;
      std::uint8_t iFlags;
  };

  static_assert(sizeof(SpellItemData) == 0x10, "SpellItemData has wrong size");
  
} // namespace CommonLib
