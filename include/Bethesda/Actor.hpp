#pragma once
#include <cstdint>
#include "Types.hpp"
#include "Bethesda/MobileObject.hpp"
#include "Bethesda/MagicCaster.hpp"
#include "Bethesda/MagicTarget.hpp"
#include "Bethesda/ActorValueOwner.hpp"
#include "Bethesda/CachedValuesOwner.hpp"
#include "Bethesda/ModifierList.hpp"
#include "Bethesda/ActionPoints.hpp"

namespace CommonLib {
  enum ACTOR_LIFE_STATE
  {
    ACTOR_LIFE_STATE_ALIVE = 0x0,
    ACTOR_LIFE_STATE_DYING = 0x1,
    ACTOR_LIFE_STATE_DEAD = 0x2,
    ACTOR_LIFE_STATE_UNCONSCIOUS = 0x3,
    ACTOR_LIFE_STATE_REANIMATE = 0x4,
    ACTOR_LIFE_STATE_RESTRAINED = 0x5,
    ACTOR_LIFE_STATE_ESSENTIAL_DOWN = 0x6,
  };

  enum ACTOR_CRITICAL_STAGE
  {
    ACS_NONE = 0x0,
    ACS_GOO_START = 0x1,
    ACS_GOO_END = 0x2,
    ACS_DISINTEGRATE_START = 0x3,
    ACS_DISINTEGRATE_END = 0x4,
    ACS_COUNT = 0x5,
  };

  class CastPowerItem;
  class bhkRagdollController;
  class bhkRagdollPenetrationUtil;
  class DispositionModifier;
  class TESActorBase;
  class ActorMover;
  class TESPackage;
  class ContinuousBeamProjectile;
  template <typename T, std::uint32_t N>
  class BSSimpleArray;
  class ActorValue;
  class ActiveEffect;
  class BGSPerk;
  class BGSPerkEntry;
  class BSSimpleListBase;
  class CombatController;
  class CombatGroup;
  class DispositionParamData;
  class ExtraDataList;
  class FurnitureMark;
  class ItemChange;
  class MagicTarget;
  class NiPoint3;
  class Projectile;
  class TESBoundObject;
  class TESObject;
  class TESObjectBOOK;
  class TESObjectCELL;
  class TESObjectREFR;
  class TESObjectWEAP;
  class TESRace;
  class TESSkill;
  class TrespassPackage;

  class Actor : 
    public MobileObject, 
    public MagicCaster, 
    public MagicTarget, 
    public ActorValueOwner, 
    public CachedValuesOwner
  {
    public:
      enum ACTOR_TYPE
      {
        ACTOR_TYPE_CREATURE = 0x0,
        ACTOR_TYPE_NPC = 0x1,
        ACTOR_TYPE_PC = 0x2,
      };

      enum COMBAT_WEAPON_TYPE
      {
        COMBAT_WEAPON_RANGED_EXPLOSIVE = 0x0,
        COMBAT_WEAPON_RANGED = 0x1,
        COMBAT_WEAPON_MELEE = 0x2,
        COMBAT_WEAPON_GRENADE = 0x3,
        COMBAT_WEAPON_MINE = 0x4,
        COMBAT_WEAPON_THROWN = 0x5,
        COMBAT_WEAPON_TYPE_COUNT = 0x6,
        COMBAT_WEAPON_TYPE_NONE = 0x6,
        COMBAT_WEAPON_TYPE_FULL_COUNT = 0x7,
      };

      enum POWER_ATTACK_TYPE {};

      enum SKILL_ACTION
      {
        SA_BLOCK = 0x0,
        SA_REPAIR = 0x0,
        SA_ATTACK = 0x0,
        SA_CAST = 0x0,
        SA_BARGAIN = 0x0,
        SA_PERSUASION = 0x0,
        SA_HIT_BY_OPPONENT = 0x0,
        SA_SECOND_OF_RUNNING = 0x0,
        SA_POTION_CREATION = 0x0,
        SA_PICK_LOCK = 0x0,
        SA_AVOID_NOTICE = 0x0,
        SA_JUMP = 0x0,
        SA_SECOND_OF_SWIMMING = 0x1,
        SA_INGREDIENT_USE = 0x1,
        SA_PICK_POCKET = 0x1,
        SA_FALL = 0x1,
        SA_SPELLHIT = 0x1,
        MAX_SKILL_ACTION = 0x2,
      };

      virtual bool IsActorAGuard();
      virtual void SetActorGuard(bool);
      virtual void SetEquippedWeight(float);
      virtual float GetEquippedWeight();
      virtual int GetFame();
      virtual int GetInfamy();
      virtual void SetIgnoreCrime(bool);
      virtual bool GetIgnoreCrime();
      virtual void Resurrect(bool, bool, bool);
      virtual void SetAdvanceNumber(int);
      virtual int GetAdvanceNumber();
      virtual void SetSkillAdvanceDelayed(ActorValue::Index);
      virtual ActorValue::Index GetSkillAdvanceDelayed();
      virtual bool DoDamage(float, float, Actor*);
      virtual void UseActionPoints(float);
      virtual void UseActionPoints(ActionPoints::Action);
      virtual int GetDisposition(Actor*, DispositionParamData*);
      virtual void UpdateMovement(float, bool);
      virtual void UpdateNonRenderSafeMovement(float, bool);
      virtual void UpdateAnimationMovementNoWorldUpdate();
      virtual float GetTurningSpeed();
      virtual bool IsOverEncumbered();
      virtual bool IsHumanoidCreature();
      virtual bool IsPc();
      virtual bool GetCannibal();
      virtual void SetCannibal(bool);
      virtual bool GetSandman();
      virtual void SetSandman(bool);
      virtual void InitiateSandmanPackage(Actor*, TESObjectREFR*, FurnitureMark*, unsigned char);
      virtual void InitiateCannibalPackage(Actor*);
      virtual TESRace* GetRace();
      virtual float GetReach();
      virtual void SetRefraction(bool, float);
      virtual void SetRagDoll(bool);
      virtual bool HasRagDoll();
      virtual ACTOR_TYPE GetActorType();
      virtual void SetActorValue(ActorValue::Index, float);
      virtual void SetActorValue(ActorValue::Index, int);
      virtual void TempModActorValue(ActorValue::Index, float, Actor*);
      virtual void TempModActorValue(ActorValue::Index, int, Actor*);
      virtual void PermanentModActorValue(ActorValue::Index, float, Actor*);
      virtual void PermanentModActorValue(ActorValue::Index, int, Actor*);
      virtual void DamageModActorValue(ActorValue::Index, float, Actor*);
      virtual void DamageModActorValue(ActorValue::Index, int, Actor*);
      virtual void ModActorBaseValue(ActorValue::Index, float);
      virtual void ModActorBaseValue(ActorValue::Index, int);
      virtual ItemChange* GetBestWeapon(COMBAT_WEAPON_TYPE);
      virtual ItemChange* GetBestAmmo();
      virtual void ResetArmorRating();
      virtual bool DamageEquipment(ItemChange*, float, bool);
      virtual TESObjectREFR* DropObject(TESObject*, ExtraDataList*, int, const NiPoint3*, const NiPoint3*);
      virtual void PickUpObject(TESObjectREFR*, int, bool);
      virtual void CastScroll(TESObjectBOOK*, MagicTarget*);
      virtual bool CheckCastWhenStrikesEnchantment(ItemChange*, Actor*, Projectile*, bool*);
      virtual void UpdateWornEnchantments(float);
      virtual bool AddSpell(SpellItem*);
      virtual bool RemoveSpell(SpellItem*);
      virtual bool ReloadWeapon(TESObjectWEAP*, int, bool);
      virtual bool ReloadWeaponNV(TESObjectWEAP*, int, bool, bool);
      virtual unsigned int UseAmmo(int);
      virtual void CheckTempModifiers();
      virtual CombatGroup* GetCombatGroup();
      virtual void SetCombatGroup(CombatGroup*);
      virtual bool InitiateTresPassPackage(TrespassPackage*);
      virtual void UpdateNonRenderSafeDialogueUpdate(float);
      virtual void InitiateSpectator();
      virtual void unknown_libname_18();
      virtual void InitiateFlee(TESObjectREFR*, bool, bool, bool, TESObjectCELL*, TESObjectREFR*, float, float);
      virtual void InitiateSearchForAttacker(TESObjectREFR*, NiPoint3, bool);
      virtual void InitiateGetUpPackage();
      virtual void SetAlpha(float);
      virtual float GetAlpha();
      virtual void StartCombat(Actor*, CombatGroup*, bool, bool, bool, int, bool, TESPackage*);
      virtual CombatController* GetCombatController();
      virtual Actor* GetCombatTarget();
      virtual void UpdateCombat();
      virtual void StopCombat(Actor*);
      virtual void PerformOneRoundofCombat();
      virtual float GetArmorRating();
      virtual float GetArmorThreshold();
      virtual int GetAttackDamage();
      virtual bool IsTresPassing();
      virtual void SetTresPassing();
      virtual bool GetUsesAttackPercents();
      virtual unsigned char GetPowerAttackPercent(POWER_ATTACK_TYPE);
      virtual float CalculateWalkSpeed();
      virtual float CalculateRunSpeed();
      virtual void ModifyDispositionTowardActor(Actor*, float);
      virtual float GetDispositionModifierTowardActor(Actor*);
      virtual void RemoveActorInDispositionModifier(Actor*);
      virtual void SetStartingPosition();
      virtual bool HasBeenAttacked();
      virtual void SetBeenAttacked(bool);
      virtual void HitMe(Actor*, float, float, const NiPoint3*, const NiPoint3*);
      virtual void UseSkill(ActorValue::Index, unsigned int);
      virtual void UseSkill(ActorValue::Index, SKILL_ACTION, float);
      virtual void UseSkill(ActorValue::Index, float, TESSkill*);
      virtual void RewardExperience(int);
      virtual float GetBaseValueOverride(ActorValue::Index, bool*);
      virtual void SetBaseValueOverride(ActorValue::Index, float);
      virtual void AddGunWobble();
      virtual void AddPerk(BGSPerk*, unsigned char, bool);
      virtual void RemovePerk(BGSPerk*, bool);
      virtual unsigned char GetPerkRank(BGSPerk*, bool);
      virtual void AddPerkEntry(BGSPerkEntry*, bool);
      virtual void RemovePerkEntry(BGSPerkEntry*, bool);
      virtual BSSimpleList<BGSPerkEntry*>* GetPerkEntryList(unsigned char, bool);
      virtual void StartAnimOn1stPerson(unsigned short, ACTION_FLAGS);
      virtual bool IsImmobile();
      virtual void HandleHealthDamage(Actor*, float);
      virtual void AttackedBy(Actor*, ActiveEffect*);
      virtual void HandleBlockedAttack(float, float, Actor*, Projectile*);
      virtual void PrecacheData();
      virtual void ProcessTracking(float);
      virtual void ProcessEmotions(float);
      virtual void CreateActorMover();
      virtual void DestroyActorMover();
      virtual NiPoint3* CalculateAnticipatedLocation(NiPoint3* result, float);


      bhkRagdollController *pRagdollController;
      bhkRagdollPenetrationUtil *pPenetrationDetection;
      DIALOGUE_EMOTION ePersuasionEmotion;
      float fEmotionValue;
      bool bProcessMe;
      Actor *pMyKiller;
      bool bMurderAlarm;
      float fCheckMyDeadBodyTimer;
      float fDeadBodyAlarm;
      ModifierList pPermanentModifiers;
      ModifierList pBaseValueOverrides;
      bool bBlockPostAnim;
      bool bReloadTargetQueued;
      bool bRunsInLow;
      BSSimpleList<CastPowerItem *> CastPowers;
      BSSimpleList<DispositionModifier *> DispModifierList;
      bool bInCombat;
      ACTOR_LIFE_STATE eLifeState;
      ACTOR_CRITICAL_STAGE eCriticalStage;
      ANIM_GROUP_ENUM eQueuedattack;
      float fLastUpdate;
      bool bDeadFlag;
      int iVisFlags;
      unsigned int iLastSeenTime;
      bool bForceRun;
      bool bForceSneak;
      bool bForceUpdateQuestTarget;
      bool bSearchingInCombat;
      Actor *pCurrentCombatTarget;
      BSSimpleArray<Actor *,1024> *pCurrentCombatTargetArray;
      BSSimpleArray<Actor *,1024> *pCurrentCombatMemberArray;
      bool bAttackOnNextTheft;
      int iThiefCrimeStamp;
      int iMinorCrimes;
      int iMajorCrimes;
      bool bIgnoreCrime;
      bool bEVPBuffered;
      bool bResetAI;
      TESActorBase *pTemplateActorBase;
      bool bInWater;
      bool bSwimming;
      bool bUpdateLighting;
      int iActionValue;
      float fTimeronAction;
      float fHeadTrackTimer;
      bool bWasInFrustum;
      bool bShouldRotateToTrack;
      NiPoint3 EditorLocCoord;
      float fEditorLocZRot;
      TESForm *pEditorLocForm;
      bool bSetOnDeath;
      bool bContainerReset;
      float fGunSkillGun;
      float fGunSkillHUD;
      float fGunSkillActor;
      float fGunSkillVATS;
      float fCurrentWeaponCondition;
      bool bFootIKInRange;
      bool bPlayerTeammate;
      bool bLightingUpdatedNonMoving;
      ActorMover *pActorMover;
      void *pLastHitData;
      TESPackage *pInitialPackage;
      float fRadiationResistanceMult;
      ContinuousBeamProjectile *pContinuousBeamPersistant;
      int iEmotion;
      int iEmotionValue;
      SIT_SLEEP_STATE cCurrentSitSleepState;
      bool bTurretBehavior;
      bool bForceHitReaction;
  };

  static_assert(sizeof(Actor) == 0x1B4, "Actor has wrong size");
  
} // namespace CommonLib
