#pragma once

class MagicItem;
class MagicCaster;
class ActiveEffect;

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
