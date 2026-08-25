#pragma once
#include "Bethesda/TESObjectREFR.hpp"

// TODO
namespace CommonLib {

  class BaseProcess;
  class MobileObject;
  class bhkCharacterController;
  class NiPoint3;
  class DialogueResponse;
  class TESPackage;
  class PackageLocation;
  class TESTopic;
  class BSSoundHandle;
  class TESIdleForm;
  class TESWorldSpace;
  class TESObjectCELL;

  class MobileObject : public TESObjectREFR
  {
    public:
      virtual bool MovetoHigh();
      virtual bool MovetoLow();
      virtual bool MovetoMiddleLow();
      virtual bool MovetoMiddleHigh();
      virtual bhkCharacterController* Move(float, NiPoint3*, unsigned int);
      virtual bhkCharacterController* Jump();
      virtual void SetAvoidanceDisabled(bool);
      virtual void Process(float);
      virtual bool ChangeProcessLevel();
      virtual void UpdateInDialogue(float, DialogueResponse*, bool);
      virtual void UpdateAnimation_2(float);
      virtual bool GetEVPBuffered();
      virtual void EvaluatePackage();
      virtual bool IsInCombat(bool);
      virtual void SetDialoguewithPlayer(bool);
      virtual bool InitiateDialogue(TESPackage*);
      virtual bool InitiateDialogue_2(MobileObject*, PackageLocation*, PackageLocation*, bool, bool, bool, TESTopic*, bool, bool);
      virtual float SpeakSoundFunction(const char*, BSSoundHandle*, DIALOGUE_EMOTION, unsigned int, int, TESIdleForm*, TESIdleForm*, TESObjectREFR*, bool, bool, bool, bool, bool);
      virtual void EndDialogue();
      virtual void SetRunOnceExtraPackage(TESPackage*, char);
      virtual bool HasEditorLocation();
      virtual TESWorldSpace* GetEditorLocationWorld();
      virtual TESObjectCELL* GetEditorLocationInteriorCell();
      virtual NiPoint3* GetEditorLocationCoord(NiPoint3*);
      virtual bool DetachCharController();
      virtual bool RemoveCharController();
      virtual void SetPosition(const NiPoint3*);
      virtual void GetLinearVelocity(NiPoint3*);
      virtual void EvaluateDetection(float);
      virtual float GetDetectionTimer();
      virtual void ReduceDetectionTimer();
      virtual float GetHeading(bool);
      virtual void SetHeading(TESObjectREFR*);
      virtual void SetHeading_2(float);
      virtual TESObjectREFR* GetCurrentTarget();
      virtual bool IsAtPoint(const NiPoint3*, float, bool, bool);
      virtual int GetSpeakingEmotion();
      virtual void SetSpeakingEmotion(int);
      virtual int GetSpeakingEmotionValue();
      virtual void SetSpeakingEmotionValue(int);
      virtual void SetSize(float);
      virtual float GetAcrobatics();
      virtual bool IsDying();
      virtual bool IsTransient();
      virtual void SetDisplayGeometry(bool);
      virtual void PutCreatedPackage(TESPackage*, bool, bool);
      virtual void Update(float);
      virtual void CleanUpPointersOnDisable();
      virtual MobileObject* SetUpTalkingActivatorActor(MobileObject*, MobileObject**);

      BaseProcess *pCurrentProcess;
      TESObjectREFR *pTalkingActivator;
      MobileObject *pDialogueItemTarget;
      float fUpdateTargetTimer;
      float fSayToFailVoiceTimer;
      bool bSpeakingDone;
      bool bTalkingToPlayer;
      bool bIgnoreChangeAnimationCall;
      bool bSoundFileDone;
      bool bVoiceFileDone;
      bool bTalkingActivator;
      bool bInTempChangeList;
      bool bDoNotRunSayToCallBack;
      char cSoundCallBackSet;
      bool bSoundCallBackSuccess;
      bool bUseEmotion;
      bool bRunsInLow;
  };

  static_assert(sizeof(MobileObject) == 0x88, "MobileObject has wrong size");
  
} // namespace CommonLib
