#pragma once
#include <cstdint>
#include "Types.hpp"
#include "Bethesda/MobileObject.hpp"
#include "Bethesda/MagicCaster.hpp"
#include "Bethesda/MagicTarget.hpp"
#include "Bethesda/ActorValueOwner.hpp"
#include "Bethesda/CachedValuesOwner.hpp"
#include "Bethesda/ModifierList.hpp"

// TODO
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

  enum SIT_SLEEP_STATE
  {
    SIT_SLEEP_NORMAL = 0x0,
    SIT_SLEEP_LOAD_SIT_IDLE = 0x1,
    SIT_SLEEP_WANT_TO_SIT = 0x2,
    SIT_SLEEP_WAITING_FOR_SIT_ANIM = 0x3,
    SIT_SLEEP_IS_SITTING = 0x4,
    SIT_SLEEP_WANT_TO_STAND = 0x5,
    SIT_SLEEP_LOAD_SLEEP_IDLE = 0x6,
    SIT_SLEEP_WANT_TO_SLEEP = 0x7,
    SIT_SLEEP_WAITING_FOR_SLEEP_ANIM = 0x8,
    SIT_SLEEP_IS_SLEEPING = 0x9,
    SIT_SLEEP_WANT_TO_WAKE = 0xA,
    SIT_SLEEP_COUNT = 0xB,
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

  class Actor : 
    public MobileObject, 
    public MagicCaster, 
    public MagicTarget, 
    public ActorValueOwner, 
    public CachedValuesOwner
  {
    public:
      Actor();
      virtual ~Actor();

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
