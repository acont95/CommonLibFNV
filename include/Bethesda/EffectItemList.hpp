#pragma once
#include "Bethesda/BSSimpleList.hpp"

class EffectItemList : BSSimpleList<EffectItem*> {
  public:
    EffectItemList();
    ~EffectItemList();

    int iHostileCount;
};

static_assert(sizeof(EffectItemList) == 0x10, "EffectItemList has wrong size");
