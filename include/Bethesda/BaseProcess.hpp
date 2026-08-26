#pragma once
#include "Types.hpp"
#include "Bethesda/ActorPackage.hpp"
#include "Bethesda/AnimIdle.hpp"
#include "Bethesda/Actor.hpp"
#include "Bethesda/MagicSystem.hpp"
#include "Bethesda/BGSBodyPart.hpp"

namespace CommonLib {

  class CachedValues;
  class MobileObject;
  class TESObjectREFR;
  class TESIdleForm;
  class MagicItem;
  class NiPoint3;
  class NiNode;
  class TESObjectCELL;
  class TESWorldSpace;
  class TESPackage;
  class ObjectstoAcquire;
  class BSFaceGenAnimationData;
  class ItemChange;
  class ExtraDataList;
  class TESBoundObject;
  class NiAVObject;
  class NiControllerManager;
  class BipedAnim;
  class Animation;
  class ActorPackageData;
  class bhkCharacterController;
  class DetectionState;
  class DetectionEvent;
  class WadingWaterData;
  class TESTopic;
  class DialogueItem;
  class PathingAvoidNodeArray;
  class FurnitureMark;
  class BSShaderPPLightingProperty;
  class TESActorBase;
  class MagicCaster;
  class SpellItem;
  class MagicTarget;
  class BSAnimGroupSequence;
  class BSBound;
  class BSSoundHandle;
  class Crime;
  class CombatGroup;
  class LipSynchAnim;
  class TESObjectWEAP;
  class TESEffectShader;
  class BGSBodyPartData;
  class ArrowProjectile;
  class Projectile;
  class MuzzleFlash;
  class BSFaceGenNiNode;
  class KFModel;
  class HitData;
  class TESObjectSTAT;

  enum PROCESS_TYPE
  {
    PROCESS_TYPE_NONE = 0xFFFFFFFF,
    PROCESS_TYPE_HIGH = 0x0,
    PROCESS_TYPE_MIDDLE_HIGH = 0x1,
    PROCESS_TYPE_MIDDLE_LOW = 0x2,
    PROCESS_TYPE_LOW = 0x3,
    PROCESS_TYPE_COUNT = 0x4,
  };

  class BaseProcess
  {
    public:
      enum FADE_STATE
      {
        FADE_NORMAL = 0x0,
        FADE_IN = 0x1,
        FADE_OUT = 0x2,
        FADE_TELEPORT_IN = 0x3,
        FADE_TELEPORT_OUT = 0x4,
        FADE_OUT_DISABLE = 0x5,
        FADE_OUT_DELETE = 0x6,
        FADE_OUT_MOVE = 0x7,
      };

      enum POSTANIM_ACTION
      {
        POSTANIM_ACTION_NONE = 0x0,
        POSTANIM_ACTION_FIRE_WEAPON = 0x1,
        POSTANIM_ACTION_RELOAD_WEAPON = 0x2,
        POSTANIM_ACTION_SIT_SLEEP = 0x4,
        POSTANIM_ACTION_GET_UP = 0x8,
        POSTANIM_ACTION_PLAY_IDLE = 0x10,
        POSTANIM_ACTION_DIE = 0x20,
        POSTANIM_ACTION_EQUIP_UNEQUIP_WEAPON = 0x40,
        POSTANIM_ACTION_PICK_IDLE_CALL = 0x80,
        POSTANIM_ACTION_HAND_GRIP_WEAPON = 0x100,
        POSTANIM_ACTION_GETOUT_OF_FURNITURE = 0x200,
        POSTANIM_FORCEIDLE_ANIMATION = 0x400,
        POSTANIM_FREEUP_SPECIAL_IDLE = 0x800,
        POSTANIM_RELOAD_TARGETS = 0x1000,
        POSTANIM_ACTION_IDLE_LOADED = 0x2000,
        POSTANIM_ACTION_HAVOKWEAPON = 0x4000,
        POSTANIM_ACTION_BLOCK = 0x8000,
        POSTANIM_ACTION_SET_IRON_SIGHTS = 0x10000,
        POSTANIM_ACTION_EXPEL_SHELLCASING = 0x20000,
        POSTANIM_ACTION_RELOAD_SINGLE = 0x40000,
        POSTANIM_ACTION_START_LOOPING_RELOAD = 0x80000,
      };

      enum HEAD_TRACK_TYPE
      {
        HEAD_TRACK_TYPE_DEFAULT = 0x0,
        HEAD_TRACK_TYPE_ACTION = 0x1,
        HEAD_TRACK_TYPE_SCRIPT = 0x2,
        HEAD_TRACK_TYPE_COMBAT = 0x3,
        HEAD_TRACK_TYPE_DIALOG = 0x4,
        HEAD_TRACK_TYPE_USE_WEAPON = 0x5,
        HEAD_TRACK_TYPE_COUNT = 0x6,
      };

      virtual void dtr_BaseProcess();
      virtual void Copy(BaseProcess*);
      virtual void HandleDeletedReference(TESObjectREFR*);
      virtual void Update(MobileObject*, float);
      virtual void Update_2(MobileObject*);
      virtual void UpdateMissedPackages(MobileObject*, bool);
      virtual const NiPoint3* GetCurrentPackageLocation(const NiPoint3* result, Actor*);
      virtual NiPoint3* GetLastPositionDetected(NiPoint3* result, Actor*, std::int32_t);
      virtual float GetLastTimeDetected(Actor*, std::int32_t);
      virtual bool CheckforNewPackage(Actor*, bool);
      virtual void ComputeLastTimeProcessed();
      virtual bool IsWandering();
      virtual std::int32_t GetProcessedDay();
      virtual std::int32_t GetProcessedMonth();
      virtual std::int32_t GetProcessedYear();
      virtual void SetPackageEvaluateHour(std::int32_t);
      virtual std::int32_t GetPackageEvaluateHour();
      virtual bool SetupSpecialIdle(MobileObject*, TESIdleForm*, AnimIdle::PLAY_TYPE_ENUM, bool, bool, bool);
      virtual void SetLastSeenLocation();
      virtual MagicItem* GetCurrentPackageSpell();
      virtual void SetCurrentPackageSpell(MagicItem*);
      virtual void PerformOneRoundofCombat(Actor*, std::int32_t);
      virtual void ClearFaceAnimationData();
      virtual void UpdateHealthBar(Actor*);
      virtual bool GetIdleDoneOnce();
      virtual void SetIdleDoneOnce(bool);
      virtual bool EvaluateDetection(Actor*);
      virtual void EvaluateCombatDetectionLists(Actor*);
      virtual bool ShouldRunPlayerDetection(Actor*);
      virtual bool ProcessActivateOneHour(Actor*, float);
      virtual bool IsDoingSayTo();
      virtual void ProcessSandman(Actor*);
      virtual void ProcessCannibal(Actor*);
      virtual void ClearFurniture(Actor*);
      virtual void SetDoingSayTo(bool);
      virtual bool SetTargetForPackage(Actor*);
      virtual TESObjectREFR* SetLocationForPackage(Actor*, bool);
      virtual TESObjectREFR* GetCurrentDestinationReference(Actor*, bool);
      virtual NiPoint3* GetCurrentDestinationCoordinate(NiPoint3* result, Actor*, bool);
      virtual TESObjectCELL* GetCurrentDestinationCell(Actor*);
      virtual TESWorldSpace* GetCurrentDestinationWorldSpace(Actor*);
      virtual float GetCurrentDestinationRadius(Actor*);
      virtual MobileObject* GetDialogTarget();
      virtual void ClearDialogTarget();
      virtual bool CheckAndStartCombatControllerForPackage(Actor*, TESPackage*, bool);
      virtual bool ShouldUpdateCombatControllerOrEndCombat(Actor*, TESPackage**);
      virtual float GetSocialTalkTimer();
      virtual void SetSocialTalkTimer(float);
      virtual void RemoveSpokenToActor(Actor*);
      virtual void ProcessRemoveWorn(Actor*, bool);
      virtual void CreateFollowforEscort(Actor*, TESPackage*, bool);
      virtual bool GetDetectAlert();
      virtual void SetDetectAlert(bool);
      virtual void RandomlyPlaySpecialIdles(Actor*);
      virtual void PostAnimFreeUpSpecialIdle(Actor*);
      virtual void ResetSearchTimer();
      virtual void ModEssentialDownTimer();
      virtual float GetEssentialDownTimer();
      virtual void SetEssentialDownTimer(float);
      virtual void ResetSearchChatterTimer();
      virtual DetectionState* InsertIntoDetectionList(Actor*, DETECTION_LEVEL, bool, std::int32_t, std::int32_t, bool, bool);
      virtual BSSimpleList<DetectionState*>* GetWhoDetectsMe(Actor*);
      virtual DetectionEvent* GetActorsDetectionEvent(Actor*);
      virtual void SetActorsDetectionEvent(Actor*, NiPoint3, std::int32_t, std::int32_t, TESObjectREFR*);
      virtual void RemoveDetectionEvent();
      virtual void CheckForExpiredDetectionEvent();
      virtual float GetWeaponScore();
      virtual void SetWeaponScore(float);
      virtual bool GetPickpocketed();
      virtual void SetPickpocketed(bool);
      virtual void SetCurrentActionComplete(bool);
      virtual bool GetCurrentActionComplete();
      virtual void SetCurrentMovementComplete(bool);
      virtual bool GetCurrentMovementComplete();
      virtual TESObjectREFR* GetTarget();
      virtual void SetTarget(TESObjectREFR*);
      virtual TESObjectREFR* GetDoor();
      virtual void SetDoor(TESObjectREFR*);
      virtual void SetAcquireObject(ObjectstoAcquire*);
      virtual ObjectstoAcquire* GetSavedAcquireObject();
      virtual void SetSavedAcquireObject(ObjectstoAcquire*);
      virtual BSFaceGenAnimationData* GetFaceAnimationData(Actor*);
      virtual ItemChange* GetCurrentWeapon();
      virtual ItemChange* GetCurrentAmmo();
      virtual bool GetLipQuequed();
      virtual void SetLipQuequed(bool);
      virtual std::int32_t GetNumberOfItemsActivated();
      virtual void SetNumberOfItemsActivated(std::int32_t);
      virtual bool SetCurrentWeapon(ItemChange*, NiNode*, bool);
      virtual bool SetCurrentTorch(ItemChange*);
      virtual bool SetCurrentAmmo(ItemChange*);
      virtual bool SetCurrentShield(ItemChange*);
      virtual void ResolveEquipmentQueue(Actor*);
      virtual bool IsItemQueued(TESBoundObject*, ExtraDataList*, bool);
      virtual void AddQueuedItem(Actor*, bool, TESBoundObject*, std::int32_t, ExtraDataList*, bool, bool, bool, bool, bool, bool);
      virtual void RemoveQueuedItem(TESBoundObject*, ExtraDataList*);
      virtual void RemoveAllQueuedItems();
      virtual NiAVObject* GetFireNode();
      virtual void SetFireNode(NiAVObject*);
      virtual void StoreBonePointers(NiControllerManager*, NiNode*);
      virtual NiNode* GetWeaponBone(BipedAnim*);
      virtual NiNode* GetTorchBone(BipedAnim*);
      virtual NiNode* GetShieldBone(BipedAnim*);
      virtual NiNode* GetQuiverBone(BipedAnim*);
      virtual NiNode* GetRightWeaponBone(BipedAnim*);
      virtual NiNode* GetLeftWeaponBone(BipedAnim*);
      virtual bool IsCurrentWeaponGrenade();
      virtual bool IsCurrentWeaponMine();
      virtual bool IsCurrentWeaponGrenadeOrMine();
      virtual bool IsCurrentWeaponThrown();
      virtual Animation* GetAnimation();
      virtual bool GetLockedLocation();
      virtual void SetLockedLocation(bool);
      virtual bool GetIsAggressor();
      virtual void SetIsAggressor(bool);
      virtual void ForceWeaponDrawnSheathed(bool, BipedAnim*, Animation*, Actor*);
      virtual void SetItemBeingUsed(TESBoundObject*);
      virtual TESBoundObject* GetItemBeingUsed();
      virtual void UpdateReparentWeapon(Actor*);
      virtual void CreateFollownoEscort(Actor*, bool);
      virtual float GetAwarePlayerTimer();
      virtual void ModAwarePlayerTimer(float);
      virtual void SetCombatDelayTimer(float);
      virtual bool CheckCombatDelayTimer();
      virtual void AddTalkedtoActor(Actor*);
      virtual bool ComputeCanInitiateDialogueWithNPC(Actor*, Actor*);
      virtual bool ComputeCanRespondToDialogueFromNPC(Actor*, Actor*);
      virtual bool IsActorInsideAmbushArea(Actor*, Actor*);
      virtual bool CheckIfThereSomeoneTalkWith(Actor*);
      virtual bool ComputeAllowSandboxConversation(Actor*, Actor*);
      virtual float GetPotentialThreatDamage(Actor*, Actor*);
      virtual TESPackage* GetRunOncePackage();
      virtual void SetRunOncePackage(TESPackage*, MobileObject*);
      virtual void ClearRunOncePackage();
      virtual void SetRunOnceProcedureIndex(std::int32_t);
      virtual std::int32_t GetRunOnceProcedureIndex();
      virtual void AddToRunOnceProcedureIndex(std::int32_t);
      virtual void ClearGreetingInfoData();
      virtual bool IsPackageDone(Actor*);
      virtual TESPackage* GetCurrentPackage();
      virtual void SetCurrentPackage(TESPackage*, MobileObject*);
      virtual void ClearCurrentPackage();
      virtual void SetCurrentProcedureIndex(std::int32_t);
      virtual std::int32_t GetCurrentProcedureIndex();
      virtual void AddToCurrentProcedureIndex(std::int32_t);
      virtual void SetupNewPackage();
      virtual DialogueItem* GetSubtitleItem();
      virtual void SetSubtitleItem(DialogueItem*);
      virtual void AddAvoidPathingArea(Actor*, NiPoint3, float, float, TESObjectREFR*, TESObjectSTAT*);
      virtual PathingAvoidNodeArray* CreateAvoidArray(Actor*);
      virtual bool IsAvoidAreaInAvoidPathingList(TESObjectREFR*);
      virtual void SetAvoidWaitTimer(float);
      virtual void RemoveAvoidPathingNode(TESObjectREFR*);
      virtual float GetHeadTrackChangeTimer();
      virtual void SetHeadTrackChangeTimer(float);
      virtual void ClearLastHeadTrackTarget();
      virtual ActorPackageData* GetRunOncePackageInstanceData();
      virtual ActorPackageData* GetInstanceDataThatIsRunning();
      virtual ActorPackage* GetActorPackageThatIsRunning();
      virtual TESPackage* GetPackageThatIsRunning();
      virtual std::int32_t GetProcedureIndexRunning();
      virtual void SetProcedureIndexRunning(std::int32_t);
      virtual void AddToProcedureIndexRunning(MobileObject*, std::int32_t);
      virtual bhkCharacterController* GetCharController();
      virtual void SetCharController(NiPointer<bhkCharacterController>);
      virtual void EndMoveMessage(Actor*);
      virtual void ProcessFollow(Actor*, bool, std::int32_t, bool);
      virtual void ProcessPursue(Actor*, bool, bool, std::int32_t);
      virtual void ProcessFlee(Actor*);
      virtual void ProcessGreet(Actor*, TESTopic*, bool, bool, bool, bool);
      virtual void ProcessObserveCombat(Actor*);
      virtual void ProcessGetUpOneHour(Actor*);
      virtual bool SitOrSleep(Actor*);
      virtual bool ShouldDisableCharController(TESObjectREFR*, std::uint32_t);
      virtual bool ProcessGetUp(Actor*);
      virtual void ProcessTravel(Actor*, bool, bool, std::int32_t, bool);
      virtual WadingWaterData* GetWadingWaterData();
      virtual void RemoveDetectionActor(Actor*, std::int32_t);
      virtual void SetDetectionTimer(float);
      virtual bool GetLineSightonActor(Actor*, Actor*, std::int32_t, bool);
      virtual bool Get360LineSightonActor(Actor*, Actor*, std::int32_t);
      virtual std::int32_t GetDetectionActor(Actor*, std::int32_t);
      virtual bool GetTalkingtoPC();
      virtual void SetTalkingtoPC(bool);
      virtual void UpdateFollowers(Actor*, float);
      virtual std::int32_t GetEmotionsDispostion(Actor*, TESObjectREFR*);
      virtual DIALOGUE_EMOTION GetLastSpeakingEmotion();
      virtual void SetLastSpeakingEmotion(DIALOGUE_EMOTION);
      virtual void RunDetection(Actor*, float);
      virtual float GetDetectionTimer();
      virtual void ReduceDetectionTimer();
      virtual void SetBreathTimer(float);
      virtual float GetBreathTimer();
      virtual void SetSurfacing(bool);
      virtual bool GetSurfacing();
      virtual bool GetGreetingFlag();
      virtual void SetGreetingFlag(bool);
      virtual float GetSoundDelay();
      virtual void SetSoundDelay(float);
      virtual bool GetAlert();
      virtual void SetAlert(bool);
      virtual bool GetFinishingCombatPackage();
      virtual void SetFinishingCombatPackage(bool);
      virtual ItemChange* CreateWeaponAcquireList(Actor*, PACKAGE_OBJECT_TYPE);
      virtual void ClearAcquireList();
      virtual float GetIdleTimer();
      virtual void SetIdleTimer(float);
      virtual bool EnterCombat(Actor*, Actor*, bool, bool, CombatGroup*, bool, bool, bool, char, bool, bool, bool, TESPackage*);
      virtual void GuardCallforHelp(Actor*, Actor*);
      virtual void CallforHelp(Actor*, Actor*, Crime*);
      virtual void SetNumberGuardsArresting(std::int32_t);
      virtual std::int32_t CalculateMoveMode(Actor*, float, float, float, bool, bool);
      virtual void SetActorsAnimation(Actor*, std::int32_t, bool);
      virtual void FinishDying(Actor*);
      virtual bool ProcessStandOff(Actor*, float, std::int32_t);
      virtual bool IsRunningRunOnce();
      virtual bool IsAFollower();
      virtual void SetFollower(bool);
      virtual std::int32_t GetWeaponCondition(Actor*);
      virtual bool GetWaitingforLipFile();
      virtual void SetWaitingforLipFile(bool);
      virtual void SetLipFileFailed(bool);
      virtual bool GetLipFileFailed();
      virtual LipSynchAnim* GetLipAnim();
      virtual void SetLipAnim(LipSynchAnim*);
      virtual void SetPlantedExplosive(bool);
      virtual bool GetPlantedExplosive();
      virtual TESIdleForm* GetLastIdlePlayed();
      virtual void SetLastIdlePlayed(TESIdleForm*);
      virtual void FreeUpSpecialIdle(Actor*);
      virtual std::int32_t GetActorValue(TESActorBase*, ActorValue::Index, Actor*);
      virtual float GetActorFloatValue(TESActorBase*, ActorValue::Index, Actor*);
      virtual void TempModActorValue(Actor*, ActorValue::Index, float);
      virtual void TempModActorValue_2(Actor*, ActorValue::Index, std::int32_t);
      virtual void DamageModActorValue(Actor*, ActorValue::Index, float);
      virtual void DamageModActorValue_2(Actor*, ActorValue::Index, std::int32_t);
      virtual void SetCachedActorValueOutOfDate(ActorValue::Index);
      virtual void InitializeActiveEffectList();
      virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList();
      virtual void DestroyActiveEffectList();
      virtual void CastAbility(MagicCaster*, SpellItem*, bool);
      virtual void TransferDisease(MagicCaster*, SpellItem*, MagicTarget*, bool);
      virtual MagicItem* GetCurrentSpell();
      virtual void SetCurrentSpell(MagicItem*);
      virtual MagicTarget* GetDesiredTarget();
      virtual void SetDesiredTarget(MagicTarget*);
      virtual bool GetShouldCheckMagicNode();
      virtual void SetShouldCheckMagicNode(bool);
      virtual void Move(MobileObject*, NiPoint3);
      virtual ANIMATION_ACTION GetAnimAction();
      virtual BSAnimGroupSequence* GetAnimActionAnimSeq();
      virtual void SetAnimAction(ANIMATION_ACTION, BSAnimGroupSequence*);
      virtual bool GetAutomaticFireAtLeastOnce();
      virtual void SetAutomaticFireAtLeastOnce(bool);
      virtual bool CanAttack();
      virtual bool CanForceGreet(Actor*);
      virtual void SetIronSights(bool);
      virtual bool GetIronSights();
      virtual bool HasMovementAnim(ANIM_GROUP_ENUM);
      virtual KNOCK_STATE_ENUM GetKnockState();
      virtual void SetKnockState(KNOCK_STATE_ENUM);
      virtual void KnockDown(Actor*);
      virtual void KnockExplosion(Actor*, NiPoint3, float);
      virtual void UpdateKnockState(Actor*);
      virtual void ClearKnockState(Actor*);
      virtual void SetAimSequence(AIM_ENUM, BSAnimGroupSequence*);
      virtual void UpdateAimSequences(Actor*);
      virtual float GetAimLooking();
      virtual void AddGunDrift(float);
      virtual void ClearAutomaticShotsToFire(bool);
      virtual std::uint8_t GetAutomaticShotsToFire(Actor*);
      virtual void SetShotsToFire(std::uint8_t);
      virtual std::uint8_t GetShotsToFire();
      virtual float GetAutomaticShotDelay();
      virtual void AttackCallback(std::int32_t);
      virtual bool GetWantWeaponDrawn();
      virtual void SetWantWeaponDrawn(bool);
      virtual bool GetWeaponDrawn();
      virtual void SetWeaponDrawn(Actor*, bool);
      virtual void SaveWeaponLastPos(NiPoint3);
      virtual const NiPoint3* GetWeaponLastPos();
      virtual void Update3dModel(Actor*);
      virtual void Set3DUpdateFlag(RESET_3D_FLAGS);
      virtual void Clear3DUpdateFlag(RESET_3D_FLAGS);
      virtual void ClearAll3DUpdateFlags();
      virtual bool Get3DUpdateFlag(RESET_3D_FLAGS);
      virtual std::uint8_t GetAll3DUpdateFlags();
      virtual void ClearObjectFromAcquireList(TESObjectREFR*);
      virtual void ClearObjectFromAcquireList_2(std::uint32_t);
      virtual TESObjectREFR* GetLastGreeted();
      virtual void SetLastGreeted(TESObjectREFR*);
      virtual BSSoundHandle* GetSoundHandle(BSSoundHandle* result, ACTOR_SOUND_HANDLE);
      virtual void SetSoundHandle(ACTOR_SOUND_HANDLE, BSSoundHandle);
      virtual void StopSoundHandle(ACTOR_SOUND_HANDLE);
      virtual void StartTorchSound(Actor*);
      virtual bool GetMovementStoped();
      virtual void ClearMovementStoped();
      virtual void SetDetectionModifier(float);
      virtual void SetDetectionModifierTimer();
      virtual float GetDetectionModifier();
      virtual float GetGreetingTimer();
      virtual void SetGreetingTimer(float);
      virtual bool IsTalking(MobileObject*);
      virtual SIT_SLEEP_STATE GetSitSleepState();
      virtual void SetSitSleepState(Actor*, SIT_SLEEP_STATE, TESObjectREFR*, std::uint8_t);
      virtual std::uint32_t GetFurnitureMarkerID();
      virtual TESObjectREFR* GetCurrentFurniture();
      virtual void SetCurrentFurniture(TESObjectREFR*);
      virtual std::uint32_t GetCurrentFurnitureIndex();
      virtual FurnitureMark* GetFurnitureMarker();
      virtual bool LoadDynamicIdle(Actor*);
      virtual void LoadSitSleepIdle(Actor*, Animation*);
      virtual bool ContinuingPackageforPC();
      virtual void SetContinuingPackage(bool);
      virtual bool IsTargetActivated();
      virtual void SetTargetActivated(bool);
      virtual bool HasBeenAttacked();
      virtual void SetBeenAttacked(bool);
      virtual BSShaderPPLightingProperty* GetLightingShaderProperty();
      virtual void SetLightingShaderProperty(BSShaderPPLightingProperty*);
      virtual void CalculateLightValue(Actor*, bool);
      virtual DetectionState* GetDetectionState(Actor*, std::int32_t);
      virtual DetectionState* InsertIntoDetectionArray(Actor*, DETECTION_LEVEL);
      virtual float GetLightLevelTimer();
      virtual void SetLightLevelTimer(float);
      virtual TESObjectREFR* GetGenericLocation();
      virtual void SetGenericLocation(TESObjectREFR*);
      virtual TESObjectREFR* GetSecondGenericLocation();
      virtual void SetSecondGenericLocation(TESObjectREFR*);
      virtual void ClearCurrentDataforProcess(Actor*);
      virtual void SetCommandingActor(Actor*);
      virtual Actor* GetCommandingActor();
      virtual void SetLastBoundWeapon(TESObjectWEAP*);
      virtual TESObjectWEAP* GetLastBoundWeapon();
      virtual void SetPackageEndTimerValue(float);
      virtual float GetPackageEndTimerValue();
      virtual void SetFurniture(TESObjectREFR*, std::uint8_t, FurnitureMark*);
      virtual void RemoveAndAttachItems(MobileObject*);
      virtual std::uint16_t GetSaveSize(std::uint32_t, MobileObject*);
      virtual void SaveGame(BGSSaveFormBuffer*);
      virtual void SaveGame_2(std::uint32_t, MobileObject*);
      virtual void LoadGame(BGSLoadFormBuffer*);
      virtual void LoadGame_2(std::uint32_t, std::uint32_t, MobileObject*);
      virtual void InitLoadGame(BGSLoadFormBuffer*);
      virtual void InitLoadGame_2(std::uint32_t, std::uint32_t, MobileObject*);
      virtual void FinishInitLoadGame(std::uint32_t, std::uint32_t, MobileObject*);
      virtual void Revert(BGSLoadFormBuffer*);
      virtual void Revert_2(std::uint32_t, MobileObject*);
      virtual void FinishLoadGame(BGSLoadFormBuffer*);
      virtual TESEffectShader* GetWeaponEnchantmentVisuals();
      virtual void SetWeaponEnchantmentVisuals(TESEffectShader*);
      virtual bool GetShouldRefreshMagicShadersEffects();
      virtual void SetShouldRefreshMagicShadersEffects(bool, bool, bool);
      virtual void RefreshMagicShaderEffects(Actor*);
      virtual void SetBeginIdlesPlayed(bool);
      virtual bool GetBeginIdlesPlayed();
      virtual void SetEndIdlesPlayed(bool);
      virtual bool GetEndIdlesPlayed();
      virtual void StartNewPackage(Actor*, TESPackage*);
      virtual void ChangePackage(Actor*, TESPackage*);
      virtual void PackageDone(Actor*, TESPackage*);
      virtual bool IsPackageDoneOnce();
      virtual void SetPackageDoneOnce(bool);
      virtual float GetAlphaMult();
      virtual void SetAlphaMult(float);
      virtual float GetScriptRefractionPower();
      virtual void SetScriptRefractionPower(float);
      virtual void UpdateWadingWater(Actor*);
      virtual std::int32_t GetNumberGuardsArresting();
      virtual void ModNumberGuardsArresting(std::int32_t);
      virtual bool ShouldCheckFlare(BSSimpleList<ActiveEffect*>, MagicSystem::FlareType);
      virtual void SetRefreshFlareFlags();
      virtual BSSimpleList<SpellItem>* GetLeveledSpells(Actor*, bool);
      virtual void SetHasHealingSpells(std::int32_t);
      virtual std::int32_t GetHasHealingSpells();
      virtual void SetHasHealingPotions(std::int32_t);
      virtual std::int32_t GetHasHealingPotions();
      virtual float GetTemporaryModifier(ActorValue::Index);
      virtual float GetPermanentModifier(ActorValue::Index);
      virtual float GetDamageModifier(ActorValue::Index);
      virtual BSBound* GetBSBound();
      virtual void SetBSBound(BSBound*);
      virtual void SetForceNextUpdate(bool);
      virtual bool GetForceNextUpdate();
      virtual void SetNeedTalkPlayer(bool);
      virtual bool GetNeedTalkPlayer();
      virtual BSSimpleList<Actor*>* GetAggroRadiusActorList();
      virtual void NotifyGuardAboutActivation(Actor*, TESObjectREFR*, TESObjectREFR*);
      virtual FADE_STATE GetFadeState();
      virtual void AddPostAnimationAction(POSTANIM_ACTION);
      virtual POSTANIM_ACTION GetPostAnimationActions();
      virtual void ClearPostAnimationActions();
      virtual void RemovePostAnimationAction(POSTANIM_ACTION);
      virtual void SetDefaultHeadTrackTarget(TESObjectREFR*);
      virtual void SetActionHeadTrackTarget(TESObjectREFR*);
      virtual void SetScriptHeadTrackTarget(TESObjectREFR*);
      virtual void SetCombatHeadTrackTarget(TESObjectREFR*);
      virtual void SetDialogHeadTrackTarget(TESObjectREFR*);
      virtual void SetUseWeaponHeadTrackTarget(TESObjectREFR*);
      virtual void SetHeadTrackTarget(HEAD_TRACK_TYPE, TESObjectREFR*);
      virtual void ClearDefaultHeadTrackTarget();
      virtual void ClearActionHeadTrackTarget(bool);
      virtual void ClearScriptHeadTrackTarget(bool);
      virtual void ClearCombatHeadTrackTarget();
      virtual void ClearDialogHeadTrackTarget(bool);
      virtual void ClearUseWeaponHeadTrackTarget(bool);
      virtual void ModDetectionModifierTimer();
      virtual float GetDetectionModifierTimer();
      virtual void ClearAllHeadTrackTargets();
      virtual void RemoveHeadTrackTarget(TESObjectREFR*);
      virtual bool CanSetDefaultHeadTrackTarget();
      virtual bool CanSetActionHeadTrackTarget();
      virtual bool CanSetCombatHeadTrackTarget();
      virtual TESObjectREFR* GetCurrentHeadTrackTarget(HEAD_TRACK_TYPE);
      virtual TESObjectREFR* GetCurrentHeadTrackTarget_2();
      virtual HEAD_TRACK_TYPE GetCurrentHeadTrackType();
      virtual const char* GetCurrentHeadTrackTypeString();
      virtual void SetForceRotate(bool);
      virtual bool GetForceRotate();
      virtual TESObjectREFR* GetLastHeadTrackTarget();
      virtual bool IsInLastDefaultTargetArray(TESObjectREFR*);
      virtual void SetIsSummonedCreature(bool);
      virtual bool GetIsSummonedCreature();
      virtual float GetDeathTime();
      virtual void SetDeathTime(float);
      virtual void AddAttachedArrow(ArrowProjectile*);
      virtual void RemoveAttachedArrow(ArrowProjectile*);
      virtual void MoveAttachedArrowsToParentCell(TESObjectREFR*);
      virtual BSSimpleList<ArrowProjectile*>* GetAttachedArrowList();
      virtual void CreateMuzzleFlash(Projectile*, TESObjectREFR*);
      virtual MuzzleFlash* GetCurrentMuzzleFlash();
      virtual bool GetEnableMuzzleFlash();
      virtual void EnableMuzzleFlash();
      virtual void ClearMuzzleFlash();
      virtual void StoreDamageNodes(NiNode*, BGSBodyPartData*);
      virtual void StoreDismemberedLimb(BGSBodyPart::LIMB_ENUM, NiNode*);
      virtual NiNode* GetDamageNode(BGSBodyPart::LIMB_ENUM);
      virtual NiAVObject* GetHeadNode();
      virtual NiAVObject* GetTorsoNode();
      virtual bool IsSustainedFire();
      virtual void SetSustainedFire(bool);
      virtual void UpdateArmorWorn(Actor*);
      virtual bool IsHeavyBodyArmorWorn();
      virtual bool IsPowerBodyArmorWorn();
      virtual bool IsPowerArmorHelmetWorn();
      virtual bool HasBackPackWorn();
      virtual void SetCurrentlyReanimating(bool);
      virtual bool GetCurrentlyReanimating();
      virtual void UpdateRadiation(Actor*, float);
      virtual void TryReserveProjectileClones(Actor*);
      virtual void SetAnimActionSuccess(std::int32_t);
      virtual void FinishSetupSpecialIdle(Actor*);
      virtual void SavePackageToExtraData(MobileObject*);
      virtual void LoadPackageFromExtraData(MobileObject*);
      virtual TESIdleForm* GetCurrentProcessIdle();
      virtual void SetCurrentProcessIdle(TESIdleForm*);
      virtual void SetCurrentProcessAnimIdleLoaded(AnimIdle*, KFModel*);
      virtual AnimIdle* GetCurrentProcessAnimIdle();
      virtual KFModel* GetCurrentProcessAnimIdleKF();
      virtual void ModTrackedDamage(Actor*, float);
      virtual float GetTrackedDamage();
      virtual float GetActorLightLevel();
      virtual void SetActorLightLevel(float);
      virtual void DeferHideDismemberedLimb(BGSBodyPart::LIMB_ENUM, NiNode*, NiAVObject*, bool);
      virtual void UpdateDeferredHideDismemberedLimbs(Actor*, float);
      virtual void SetCreatureLipSynchAnim(LipSynchAnim*);
      virtual LipSynchAnim* GetCreatureLipSynchAnim();
      virtual void SetCreatureLipSynchStartTime(std::uint32_t);
      virtual std::uint32_t GetCreatureLipSynchStartTime();
      virtual void AddRadiationMagicDelta(float);
      virtual void RemoveRadiationMagicDelta(float);
      virtual float GetRadiationMagicDelta();
      virtual void SetRadiationWaterDelta(float);
      virtual float GetRadiationWaterDelta();
      virtual void SetRadiationDelta(float);
      virtual float GetRadiationDelta();
      virtual HitData* GetLastHitData();
      virtual void SetLastHitData(HitData*);
      virtual void ClearLastHitData();
      virtual HitData* GetLastAttackHitData();
      virtual void SetLastAttackHitData(HitData*);
      virtual void ClearLastAttackHitData();
      virtual std::int32_t GetWeaponConditionStage();
      virtual void SetWeaponConditionStage(std::int32_t);
      virtual BSFaceGenNiNode* GetFaceNode();
      virtual void SetFaceNode(BSFaceGenNiNode*);
      virtual BSFaceGenNiNode* GetFaceSkinnedNode();
      virtual void SetFaceSkinnedNode(BSFaceGenNiNode*);
      virtual NiAVObject* GetHeadAnims();
      virtual void SetHeadAnims(NiAVObject*);
      virtual void CheckCachedValueFlags(Actor*);
      virtual void SetPathLookAtTarget(TESObjectREFR*);
      virtual void ClearPathLookTarget(TESObjectREFR*);

      ActorPackage CurrentPackage;
      float fSystemTimeClock;
      float fHourLastProcessed;
      unsigned int iDateLastProcessed;
      PROCESS_TYPE eLevel;
      CachedValues *pCachedValues;
  };

  static_assert(sizeof(BaseProcess) == 0x30, "BaseProcess has wrong size");
  
} // namespace CommonLib
