#pragma once
#include <cstdint>

namespace CommonLib {

  class BGSExplosion;
  class BGSDebris;
  class TESModelTextureSwap;

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
  
} // namespace CommonLib
