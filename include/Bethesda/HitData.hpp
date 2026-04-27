#pragma once
#include "Types.hpp"
#include "Bethesda/ActorValue.hpp"
#include "Bethesda/BGSBodyPart.hpp"

// TO DO
namespace CommonLib {

  class Actor;
  class TESObjectREFR;
  class TESObjectWEAP;
  class SpellItem;
  class VATS_COMMAND;

  class HitData
  {
    public:

      Actor *pAggressor;
      Actor *pTarget;
      TESObjectREFR *pSourceRef;
      ActorValue::Index eAttackSkill;
      BGSBodyPart::LIMB_ENUM eDamageLimb;
      float fHealthDamage;
      float fTotalDamage;
      float fFatigueDamage;
      float fTargetedLimbDamage;
      float fPercentBlocked;
      float fArmorDamage;
      float fDamageToWeapon;
      TESObjectWEAP *pWeapon;
      float fWeaponHealth;
      NiPoint3 kHitLocation;
      NiPoint3 kHitDirection;
      SpellItem *pCriticalEffect;
      VATS_COMMAND *pVATSCommand;
      unsigned int uiFlags;
      float fBonusMult;
      int iRefCount;
  };

  static_assert(sizeof(HitData) == 0x64, "HitData has wrong size");
  
} // namespace CommonLib
