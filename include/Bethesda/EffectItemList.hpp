#pragma once
#include <cstdint>
#include "Bethesda/BSSimpleList.hpp"

class EffectItem;

class EffectItemList : public BSSimpleList<EffectItem*> {
  public:
    EffectItemList();
    virtual ~EffectItemList();

    std::int32_t iHostileCount;
};

static_assert(sizeof(EffectItemList) == 0x10, "EffectItemList has wrong size");
