#pragma once
#include "Bethesda/MagicSystem.hpp"
#include "Bethesda/SkillLevel.hpp"

class SpellItemData
{
  public:
    SpellItemData();
    ~SpellItemData();

    MagicSystem::SpellType iSpellType;
    int iCostOverride;
    SkillLevel::Value eLevelOverride;
    unsigned __int8 iFlags;
};

static_assert(sizeof(SpellItemData) == 0x10, "SpellItemData has wrong size");
