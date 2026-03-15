#pragma once
#include "Bethesda/MagicItemForm.hpp"
#include "Bethesda/TESWeather.hpp"
#include "Bethesda/SpellItemData.hpp"

class SpellItem : MagicItemForm
{
  public:
    SpellItem();
    virtual ~SpellItem();

    enum SpellFlag : __int32
    {
      COST_OVERRIDE = 0x1,
      ALWAYS_SUCCEEDS = 0x2,
      PC_STARTSPELL = 0x4,
      IMMUNE_TO_SILENCE = 0x8,
      IGNORE_LOS_CHECK = 0x10,
      IGNORE_RESISTANCE = 0x20,
      NO_ABSORB_REFLECT = 0x40,
      FORCE_TOUCH_EXPLODE = 0x80,
    };

    SpellItemData data;
};

static_assert(sizeof(SpellItem) == 0x44, "SpellItem has wrong size");
