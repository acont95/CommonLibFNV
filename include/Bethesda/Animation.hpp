#pragma once
#include <cstdint>
#include "Bethesda/BSSimpleList.hpp"
#include "Bethesda/KFModel.hpp"
#include "Bethesda/AnimIdle.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiNode.hpp"
#include "Gamebryo/NiControllerManager.hpp"
#include "Types.hpp"

namespace CommonLib {

  class TESObjectREFR;
  template <typename K, typename V>
  class NiTPointerMap;
  class AnimSequenceBase;
  class BSAnimGroupSequence;
  class IDLE_REPLAY_DELAY;
  class AnimIdle;

  struct ANIM_GROUP_INFO
  {
    char *pName;
    bool bMultipleSequences;
    ANIM_GROUP_SECTION eSectionLayer;
    ANIM_GROUP_ACTION_TYPE eAction;
    ANIM_GROUP_ACTION eActions[5];
  };

  class Animation
  {
    public:
      std::uint8_t m_uFlags;
      TESObjectREFR *pActorRef;
      NiPointer<NiNode> pAnimRoot;
      NiNode *pAccumRoot;
      NiPoint3 movementDelta;
      NiPoint3 AccumRootTranslate;
      NiAVObject *pSoundPriorityBone[8];
      float m_fLooking;
      std::uint16_t group[8];
      ANIM_GROUP_ACTION action[8];
      int loopCount[8];
      std::uint16_t nextGroup[8];
      int nextLoops[8];
      char cSkipUpdate;
      bool bShutDown;
      float time;
      float fLipTime;
      NiPointer<NiControllerManager> spManager;
      NiTPointerMap<unsigned short,AnimSequenceBase *> *pAnimSequenceMap;
      BSAnimGroupSequence *pCurrentSequence[8];
      BSAnimGroupSequence *pLastMovementSequence;
      BSSimpleList<KFModel *> kfModelList;
      float m_fMoveSpeed;
      float m_fAttackSpeed;
      float m_fGlobalTimeMultiplier;
      float m_fReloadModifier;
      float m_fEquipModifier;
      char cSkipNextBlend;
      std::uint16_t sQueuedReloadGroup;
      NiPointer<AnimIdle> spAnimIdle;
      NiPointer<AnimIdle> spAnimIdleQueued;
      NiPointer<AnimIdle> spAnimIdleFreeWhenInactiveA[2];
      BSSimpleList<IDLE_REPLAY_DELAY *> replayDelayList;
  };

  static_assert(sizeof(ANIM_GROUP_INFO) == 0x24, "ANIM_GROUP_INFO has wrong size");
  static_assert(sizeof(Animation) == 0x13C, "Animation has wrong size");
  
} // namespace CommonLib
