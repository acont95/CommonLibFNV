#pragma once
#include "Bethesda/BSSimpleList.hpp"

class TESConditionItem;

class TESCondition
{
  public:
    TESCondition();
    ~TESCondition();

    BSSimpleList<TESConditionItem*> listConditions;
};

static_assert(sizeof(TESCondition) == 0x8, "TESCondition has wrong size");
