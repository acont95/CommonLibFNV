#pragma once
#include "Types.hpp"
#include "Bethesda/MobileObject.hpp"
#include "Bethesda/BSSimpleList.hpp"
#include "Bethesda/ProjectilePickCache.hpp"
#include "Bethesda/ActorCause.hpp"
#include "Bethesda/BSSoundHandle.hpp"
#include "Bethesda/BGSBodyPart.hpp"
#include "Gamebryo/NiPoint3.hpp"
#include "Gamebryo/NiLight.hpp"

// TO DO
namespace CommonLib {

  class hkpWorldObject;
  class TESObjectWEAP;
  class TESObjectREFR;
  class ProjectileTarget;
  class ItemChange;

  class Projectile : public MobileObject
  {
    public:
      Projectile();
      virtual ~Projectile();

      enum ProjectileFlags
      {
        HITSCAN_MODE = 0x1,
        NO_3D = 0x2,
        NO_CHARCONTROLLER = 0x4,
        NO_COLLISION = 0x8,
        TRACER = 0x10,
        FADING = 0x20,
        REORIENT = 0x40,
        POST_PROCESS = 0x80,
        CHECK_BEHIND_WALL = 0x100,
        TURNED_OFF = 0x200,
        ACTIVE_IN_INVENTORY = 0x400,
        INVENTORY_FREAKOUT = 0x800,
        ALWAYS_HIT_TARGET = 0x1000,
        SPAWN_EXPLOSION_AT_IMPACT = 0x2000,
        NO_PLAYER_PROXIMITY = 0x4000,
        KILL_ON_EXPLOSION = 0x8000,
        PROJECTILE_INITIALIZED = 0x10000,
        FAKE_SHOT = 0x20000,
        WHOLE_BODY_TARGETED = 0x40000,
        SHOOTER_IN_COMBAT = 0x80000,
        DETONATE = 0x100000,
      };

      enum PROJECTILE_TYPE
      {
        PROJECTILE_TYPE_UNKNOWN = 0x0,
        PROJECTILE_TYPE_BEAM = 0x1,
        PROJECTILE_TYPE_FLAME = 0x2,
        PROJECTILE_TYPE_GRENADE = 0x3,
        PROJECTILE_TYPE_MISSILE = 0x4,
        PROJECTILE_TYPE_CONTINUOUS_BEAM = 0x5,
      };

      class ImpactData
      {
        TESObjectREFR *pCollidee;
        NiPoint3 kLocation;
        NiPoint3 kNormal;
        hkpWorldObject *pTargetWorldObject;
        MATERIAL_TYPE eMaterial;
        BGSBodyPart::LIMB_ENUM eDamageLimb;
        bool bProcessed;
        bool bDoDamage;
        __int16 sTargetWorldObjectCount;
        __int16 sTargetWorldObjectIndex;
      };

      BSSimpleList<Projectile::ImpactData *> ImpactList;
      bool bImpactProcessed;
      NiTransform kFollowOffset;
      unsigned int iFlags;
      float fPower;
      float fSpeedMult;
      float fRange;
      float fAge;
      float fDamage;
      float fAlpha;
      float fExplosionTimer;
      float fBlinkTimer;
      float fSpreadHeading;
      float fSpreadLooking;
      float fWeaponCondition;
      TESObjectWEAP *pWeaponSource;
      TESObjectREFR *pShooter;
      TESObjectREFR *pDesiredTarget;
      NiPoint3 MovementDirection;
      float fDistanceMoved;
      NiPointer<NiLight> spLight;
      bool bSendAlarm;
      NiPointer<ProjectilePickCache> spPickCache;
      NiPointer<ActorCause> spActorCause;
      float fDecalSize;
      BSSoundHandle sndHandle;
      BSSoundHandle sndCountdown;
      ProjectileTarget *pTarget;
      ItemChange *pSecondaryItemChange;
      bool bSoundFired;
      float fSoundDist;
  };

  static_assert(sizeof(Projectile) == 0x150, "Projectile has wrong size");
  
} // namespace CommonLib
