#pragma once
#include "Bethesda/TESObjectREFR.hpp"

// TODO
namespace CommonLib {

  class BaseProcess;

  class MobileObject : public TESObjectREFR
  {
    public:
      MobileObject();
      virtual ~MobileObject();

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
