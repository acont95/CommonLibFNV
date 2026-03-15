#pragma once
#include "Bethesda/BSSimpleList.hpp"
#include "Bethesda/EffectItemData.hpp"
#include "Bethesda/EffectSetting.hpp"
#include "Bethesda/TESCondition.hpp"

class EffectItem 
{
  public:
    EffectItem();
    ~EffectItem();

    EffectItemData data;
    EffectSetting *pEffectSetting;
    float fRawCost;
    TESCondition Conditions;
};

static_assert(sizeof(EffectItem) == 0x24, "EffectItem has wrong size");
