#pragma once
#include <cstdint>

namespace CommonLib {

  class TESObjectLIGH;
  class TESSound;
  class TESObjectWEAP;
  class BGSExplosion;

  class BGSProjectileData {
    public:
      BGSProjectileData();
      ~BGSProjectileData();

      std::uint32_t iFlags;
      float fGravity;
      float fSpeed;
      float fRange;
      TESObjectLIGH* pLight;
      TESObjectLIGH* pMuzzleFlashLight;
      float fTracerChance;
      float fExplosionProximity;
      float fExplosionTimer;
      BGSExplosion* pExplosionType;
      TESSound* pActiveSoundLoop;
      float fMuzzleFlashDuration;
      float fFadeOutTime;
      float fForce;
      TESSound* pCountdownSound;
      TESSound* pDeactivateSound;
      TESObjectWEAP* pDefaultWeaponSource;
      float fRotationX;
      float fRotationY;
      float fRotationZ;
      float fBounceMultiplier;
  };

  static_assert(sizeof(BGSProjectileData) == 0x54);
  
} // namespace CommonLib
