#pragma once
#include "Bethesda/MagicSystem.hpp"
#include "Bethesda/ActorValue.hpp"


class EffectItemData
{
  public:
    EffectItemData();
    ~EffectItemData();

    int iMagnitude;
    int iArea;
    int iDuration;
    MagicSystem::Range iRange;
    ActorValue::Index iActorValue;
};

static_assert(sizeof(EffectItemData) == 0x14, "EffectItemData has wrong size");
