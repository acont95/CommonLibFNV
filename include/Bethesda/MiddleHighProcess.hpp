#pragma once
#include <cstdint>
#include "Types.hpp"
#include "Bethesda/MiddleLowProcess.hpp"
#include "Bethesda/LowProcess.hpp"
#include "Bethesda/BGSBodyPart.hpp"
#include "Bethesda/FurnitureMark.hpp"
#include "Gamebryo/NiPointer.hpp"

namespace CommonLib {

  class QueuedFile;
  class BSCloneReserver;
  class QueuedItem;
  class ArrowProjectile;
  class ActiveEffect;
  class PatrolActorPackageData;

  class MiddleHighProcess : public MiddleLowProcess
  {
    public:

      class DeferredHideLimb
      {
        float fDismemberTimer;
        BGSBodyPart::LIMB_ENUM eLimbIndex;
        NiPointer<NiNode> spDismemberedLimbRoot;
        NiPointer<NiAVObject> spReplacementLimb;
        bool bExplosion;
      };

      virtual void SetAnimation(Animation*);
      virtual bool SetupPathFinding(Actor*, NiPoint3, TESObjectCELL*, TESWorldSpace*);
      virtual void SetAnimationActiveFlag(bool);
      virtual void ResetTarget();
      virtual void ProcessBuyObject(Actor*);
      virtual void ProcessSteal(Actor*);
      virtual void ProcessPickPocket(Actor*);
      virtual void ProcessDialogue(MobileObject*);
      virtual bool ProcessDialogueActivate(Actor*);
      virtual bool ProcessUseFurniture(Actor*, TESObjectREFR*);
      virtual void ProcessRemoveWorn_2(Actor*, bool, bool);
      virtual void ProcessWander(Actor*, const NiPoint3*, float);
      virtual bool ProcessSandBoxDialogue(Actor*, TESObjectREFR*);
      virtual bool ProcessPatrolInit(Actor*, PatrolActorPackageData*);
      virtual void ProcessPatrolStartTravelToNextRef(Actor*, PatrolActorPackageData*);
      virtual void ProcessPatrolTravelingToNextRef(Actor*, PatrolActorPackageData*);
      virtual void ProcessPatrolStartAtRefBehavior(Actor*, PatrolActorPackageData*);
      virtual void ProcessPatrolAtRef(Actor*, PatrolActorPackageData*);
      virtual void ProcessUseIdleMarker(Actor*, TESObjectREFR*);
      virtual void ProcessAccompanyOneHour(Actor*);
      
      BSSimpleList<TESObjectREFR *> DeadDetectList;
      BSSimpleList<TESObjectREFR *> RefListChairBed;
      float fPursueTimer;
      float fEquippedWeight;
      bool bDoneOnce;
      bool bAimingTarget;
      bool bNeedReparentWeapon;
      bool bDrawn;
      ActorPackage RunOncePackage;
      NiPoint3 lastSeenPostion;
      PACKAGE_OBJECT_TYPE eUseItem;
      TESIdleForm *pLastIdlePlayed;
      bool bPickPackIdle;
      ItemChange *pWeapon;
      ItemChange *pAmmo;
      NiPointer<QueuedFile> spWeaponPreload;
      NiPointer<BSCloneReserver> spReserveProjectileClones;
      bool bWeaponGrenade;
      bool bWeaponMine;
      bool bWeaponThrown;
      bool bHeavyArmorWorn;
      bool bPowerArmorWorn;
      bool bPowerArmorHelmet;
      bool bHasBackPackWorn;
      NiNode *pWeaponBone;
      NiAVObject *pFireNode;
      bool bWantWeaponDrawn;
      bool bWeaponDrawn;
      NiPointer<bhkCharacterController> spCharController;
      char cKnockState;
      std::uint8_t cSitSleepState;
      TESObjectREFR *pCurrentFurniture;
      std::uint8_t cCurrentFurnitureIndex;
      FurnitureMark FurnitureMarker;
      Actor *pCommandingActor;
      TESObjectWEAP *pLastBoundWeapon;
      MagicItem *pCurrentSpell;
      MagicItem *pCurrentPackageSpell;
      bool bCheckMagicNode;
      TESEffectShader *pCurrentWeaponEffect;
      float fAlphaMult;
      float fScriptRefractPower;
      BSFaceGenAnimationData *m_pFaceAnimationData;
      bool bRefreshMagicShaderEffects;
      bool bRefreshMagicShaderEffectBody;
      bool bRefreshMagicShaderEffectWeapon;
      bool bRefreshMagicShaderEffectLoading;
      bool bRefreshFlareFlags;
      unsigned int uiFlareFlags;
      bool bPickPocketed;
      bool bDoneClothesChange;
      bool bDetectLifeDetected;
      bool bSummonedCreature;
      std::uint8_t cUpdate3DModel;
      bool bForceNextUpdate;
      int iPackageIdleNumber;
      TESIdleForm *pCurrentIdle;
      float fPackageIdleTimer;
      bool bPlayedBeginIdles;
      bool bPlayedEndIdles;
      LipSynchAnim *pCreatureLipsynchAnim;
      unsigned int iCreatureLipsynchStartTime;
      int iReservationSlot;
      BSSimpleList<ArrowProjectile *> *pAttachedArrowList;
      BSSimpleList<DeferredHideLimb *> DeferredHideLimbList;
      BSSimpleList<ActiveEffect *> *pActiveEffectList;
      MagicTarget *pDesiredTarget;
      Animation *pAnimation;
      BSAnimGroupSequence *pAimSequence[3];
      float fAimLooking;
      float fAutomaticShotDelay;
      std::uint8_t cShotsToFire;
      bool bSustainedFire;
      bool bBeenAttacked;
      NiNode *pDamageRootNode[15];
      NiAVObject *pHeadNode;
      NiAVObject *pTorsoNode;
      NiPointer<BSShaderPPLightingProperty> pLightingProperty;
      BSBound *pBSBound;
      bool bIronSights;
      std::int16_t iAnimActionSuccess;
      unsigned int iMovementAnimations;
      BSSimpleList<QueuedItem *> *pListItemstoEquipUnequip;
      float fRadiationDelta;
      float fRadiationMagicDelta;
      float fRadiationWaterDelta;
      HitData *pLastHitData;
      int iWeaponConditionStage;
      BSFaceGenNiNode *pFaceNode;
      BSFaceGenNiNode *pFaceNodeSkinned;
      NiAVObject *pAnimFace;
      HitData *pLastAttackHitData;
      unsigned int nFurnitureListTimer;
  };

  static_assert(sizeof(MiddleHighProcess) == 0x25C, "MiddleHighProcess has wrong size");
  
} // namespace CommonLib
