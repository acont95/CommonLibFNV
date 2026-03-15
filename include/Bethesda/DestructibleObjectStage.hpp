#pragma once
#include <cstdint>
#include "Bethesda/BGSExplosion.hpp"
#include "Bethesda/BGSDebris.hpp"
#include "Bethesda/TESModelTextureSwap.hpp"

class DestructibleObjectStage
{
  public:
    DestructibleObjectStage();
    ~DestructibleObjectStage();

    uint8_t cModelDamageStage;
    uint8_t cHealthPercentage;
    uint8_t cFlags;
    uint32_t iSelfDamagePerSecond;
    BGSExplosion* pExplosion;
    BGSDebris* pDebris;
    uint32_t iDebrisCount;
    TESModelTextureSwap* pReplacementModel;
};

static_assert(sizeof(DestructibleObjectStage) == 0x18); 
