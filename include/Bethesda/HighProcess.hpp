#pragma once
#include <cstdint>
#include "Types.hpp"
#include "Bethesda/MiddleHighProcess.hpp"
#include "Bethesda/BSSimpleList.hpp"
#include "Bethesda/BSSoundHandle.hpp"
#include "Gamebryo/NiPointer.hpp"

namespace CommonLib {

  class DetectionState;
  class Actor;
  class StartCombatStates;
  class NiBSBoneLODController;
  class NiBillboardNode;
  class MoveToFadeStruct;
  class ActorValueCache;
  class bhkSimpleShapePhantom;
  class AvoidAreaStruct;
  class PathingRequest;
  class ActorPathingMessageQueue;

  class HighProcess : public MiddleHighProcess
  {
    public:
      virtual BSSimpleList<Actor*>* GetAvoidActorList();

      BSSimpleList<DetectionState *> *pDetectedActorList;
      BSSimpleList<DetectionState *> *pActorsWhoDetectMeList;
      BSSimpleList<Actor *> *pLastSpokeToList;
      BSSimpleList<DetectionState *> *pThreadDetectList;
      BSSimpleList<DetectionState *> *pTempActorsWhoDetectMeList;
      bool bEvaluateDetection;
      BSSimpleList<StartCombatStates *> AggroList;
      BSSimpleList<StartCombatStates *> GroupsToHelpList;
      BSSimpleList<StartCombatStates *> TargetToAddList;
      BSSimpleList<StartCombatStates *> SpectatorList;
      float fDetectListTimer;
      float fIdleChatterTimer;
      bool bSayGoodByePlayer;
      bool bProcessGreetSayTo;
      float fClearTalkToListTimer;
      TESObjectREFR *plastDetected;
      float fTalkTimer;
      TESObjectREFR *pPathLookAtTarget;
      float fMaxAlpha;
      float fPackageEvalTimer;
      float fUseItemTimer;
      float fHoldAttackTimer;
      std::int16_t sShotsFired;
      std::int16_t sShotsToFire;
      std::int16_t sBurstsFired;
      bool bCheckDeadTalk;
      bool bSkippedUpdate;
      float fCheckToTalkTimer;
      NiNode *pNode;
      float fDelayTimer;
      float fDistanceMoved;
      float fTurnTime;
      char cLastTurnDir;
      float fEvaluateAcquireTimer;
      NiBSBoneLODController *pBoneLOD;
      int iLastBoneLOD;
      std::int16_t sAnimAction;
      BSAnimGroupSequence *pAnimSeq;
      bool bAutomaticFireAtLeastOne;
      float fDetectionTimer;
      std::int16_t iLastDetection;
      NiPoint3 WeaponLastPos;
      TESObjectREFR *pGreetActor;
      float fSoundDelay;
      BSSoundHandle SoundHandle[2];
      bool bGreetingFlag;
      float fGreetingTimer;
      float fIdleTimer;
      float fDetectGreetTimer;
      float fBreathTimer;
      bool bHeadTrack;
      float fVoiceTimer;
      bool bLipQuequed;
      bool bWeaponAlertDrawn;
      float fAwarePlayerTimer;
      TESIdleForm *pIdleToPlay;
      NiPointer<AnimIdle> spAnimIdleToPlay[2];
      NiPointer<KFModel> spAnimIdleKF[2];
      bool bDialoguewithPlayer;
      DialogueItem *pGreetTopic;
      DIALOGUE_EMOTION eLastSpeakingEmotion;
      MobileObject *pDialogTarget;
      bool bContinuingPackageforPC;
      bool bActivateAnim;
      float fScriptPackageEndTime;
      float fHealthBarAlphaValue;
      NiPointer<NiBillboardNode> spHealthBarNode;
      float fActorHealthPercentage;
      float fHealthBarEmittanceValue;
      BSSimpleList<Actor *> AggroRadiusList;
      BSSimpleList<Actor *> AvoidActorList;
      int iNumberGuardsPersuing;
      bool bStop;
      float fReEquipArmorTimer;
      bool bUnequippedArmorToSwim;
      int iHasHealingSpell;
      int iHasHealingPotion;
      BSSimpleList<SpellItem *> *pLeveledSpellList;
      char cLastTurn;
      bool bCurrentlyReanimating;
      float fDetectionModifer;
      float fDetectionModifierTimer;
      float fLightLevel;
      float fLightLevelTimer;
      LipSynchAnim *pLipSynicAnim;
      bool bWaitingForLipFile;
      bool bLipFileFailed;
      MuzzleFlash *pCurrentMuzzleFlash;
      unsigned int iDetectionCounter;
      DetectionEvent *pActorsGeneratedDetectionEvent;
      bool bFinishingCombatPackage;
      DialogueItem *m_pSayToDialogueTopic;
      BaseProcess::FADE_STATE eFadeState;
      float fFadeAlpha;
      TESObjectREFR *pTeleportFadeRef;
      MoveToFadeStruct *pMoveToFadeStruct;
      TESObjectREFR *HeadTrackingTargets[6];
      bool HeadTrackingTargetFlags[6];
      float fHeadTrackTargetTimer;
      TESObjectREFR *pLastTarget;
      bool bForceRotate;
      BaseProcess::POSTANIM_ACTION ePostAnimActon;
      ActorValueCache *pActorValueCache;
      float fCachedActorHeight;
      AnimIdle::PLAY_TYPE_ENUM eSpecialIdleType;
      NiPointer<bhkSimpleShapePhantom> spShapePhantom;
      float fDetectDoorForPathingTimer;
      float fRadiationTimer;
      float fHighestRadiation;
      bool bPlantedExplosive;
      bool bNeedTalkPlayer;
      float fTakeBackTimer;
      BSSimpleList<AvoidAreaStruct *> *pListOfAvoidAreas;
      float fAvoidWaitTimer;
      DialogueItem *pSubtitleVoice;
      bool bHiding;
      bool bIsDoingSayTo;
      NiPointer<PathingRequest> spMeToGoalRequest;
      NiPointer<PathingRequest> spEscortedToGoalRequest;
      NiPointer<ActorPathingMessageQueue> spMeToGoalMessageQueue;
      NiPointer<ActorPathingMessageQueue> spEscortedToGoalMessageQueue;
  };

  static_assert(sizeof(HighProcess) == 0x46C, "HighProcess has wrong size");
  
} // namespace CommonLib
