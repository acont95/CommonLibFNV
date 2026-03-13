#pragma once
#include "Bethesda/MagicItem.hpp"
#include "Bethesda/MagicCaster.hpp"
#include "Bethesda/ActiveEffect.hpp"

class SpellDispelData
{
  public:
    SpellDispelData();
    ~SpellDispelData();

    MagicItem* pSpell;
    MagicCaster* pCaster;
    ActiveEffect* pActiveEffect;
};

static_assert(sizeof(SpellDispelData) == 0xC, "SpellDispelData has wrong size");
