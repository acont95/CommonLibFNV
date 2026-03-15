#pragma once
#include "Bethesda/BSSimpleList.hpp"
#include "Bethesda/EffectItem.hpp"

class EffectItemList : BSSimpleList<EffectItem*> {
  public:
    EffectItemList();
    virtual ~EffectItemList();

    int iHostileCount;
};

static_assert(sizeof(EffectItemList) == 0x10, "EffectItemList has wrong size");
