#pragma once
#include "Bethesda/TESFullName.hpp"
#include "Bethesda/EffectItemList.hpp"


class MagicItem : TESFullName, EffectItemList 
{
  public:
    MagicItem();
    ~MagicItem();
};

static_assert(sizeof(MagicItem) == 0x1C, "MagicItem has wrong size");
