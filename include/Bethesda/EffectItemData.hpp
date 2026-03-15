#pragma once
#include <cstdint>
#include "Bethesda/MagicSystem.hpp"
#include "Bethesda/ActorValue.hpp"


class EffectItemData
{
  public:
    EffectItemData();
    ~EffectItemData();

    std::int32_t iMagnitude;
    std::int32_t iArea;
    std::int32_t iDuration;
    MagicSystem::Range iRange;
    ActorValue::Index iActorValue;
};

static_assert(sizeof(EffectItemData) == 0x14, "EffectItemData has wrong size");
