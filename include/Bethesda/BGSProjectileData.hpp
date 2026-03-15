#pragma once
#include <cstdint>
#include "Bethesda/TESObjectLIGH.hpp"
#include "Bethesda/TESSound.hpp"
#include "Bethesda/TESObjectWEAP.hpp"
#include "Bethesda/BGSExplosion.hpp"

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
