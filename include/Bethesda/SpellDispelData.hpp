#pragma once

namespace CommonLib {

  class MagicItem;
  class MagicCaster;
  class ActiveEffect;

  class SpellDispelData
  {
    public:

      MagicItem* pSpell;
      MagicCaster* pCaster;
      ActiveEffect* pActiveEffect;
  };

  static_assert(sizeof(SpellDispelData) == 0xC, "SpellDispelData has wrong size");
  
} // namespace CommonLib
