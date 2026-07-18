#pragma once
#include "Bethesda/BSSimpleList.hpp"
#include "Bethesda/KFModel.hpp"
#include "Bethesda/AnimIdle.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiNode.hpp"
#include "Gamebryo/NiControllerManager.hpp"

namespace CommonLib {

  class TESObjectREFR;
  template <typename K, typename V>
  class NiTPointerMap;
  class AnimSequenceBase;
  class BSAnimGroupSequence;
  class IDLE_REPLAY_DELAY;

  enum ANIM_GROUP_ACTION
  {
    AGA_NONE = 0xFFFFFFFF,
    AGA_START = 0x0,
    AGA_STOP = 0x1,
    AGA_LOOP_START = 0x0,
    AGA_LOOP_STOP = 0x1,
    AGA_SPECIAL_IDLE_START = 0x0,
    AGA_SPECIAL_IDLE_LOOP_START = 0x1,
    AGA_SPECIAL_IDLE_LOOP_STOP = 0x2,
    AGA_SPECIAL_IDLE_STOP = 0x3,
    AGA_LOOPING_RELOAD_START = 0x0,
    AGA_LOOPING_RELOAD_LOOP = 0x1,
    AGA_LOOPING_RELOAD_STOP = 0x2,
    AGA_ATTACK_START = 0x0,
    AGA_ATTACK_HIT = 0x1,
    AGA_ATTACK_EJECT = 0x2,
    AGA_ATTACK_POWER_STOP = 0x2,
    AGA_ATTACK_SWITCH = 0x3,
    AGA_ATTACK_STOP = 0x4,
    AGA_ATTACK_MINE_START = 0x0,
    AGA_ATTACK_MINE_RELEASE = 0x1,
    AGA_ATTACK_MINE_ATTACH = 0x2,
    AGA_ATTACK_MINE_STOP = 0x3,
    AGA_ATTACK_SPIN_START = 0x0,
    AGA_ATTACK_SPIN_FIRE = 0x1,
    AGA_ATTACK_SPIN_LOOP = 0x2,
    AGA_ATTACK_SPIN_STOP = 0x3,
    AGA_ATTACK_THROW_START = 0x0,
    AGA_ATTACK_THROW_HOLD = 0x1,
    AGA_ATTACK_THROW_RELEASE = 0x2,
    AGA_ATTACK_THROW_ATTACH = 0x3,
    AGA_ATTACK_THROW_STOP = 0x4,
    ANIM_GROUP_ACTION_COUNT = 0x5,
    AGA_BLOCK_START = 0x0,
    AGA_BLOCK_ATTACK = 0x1,
    AGA_BLOCK_STOP = 0x2,
    AGA_EQUIP_START = 0x0,
    AGA_EQUIP_ATTACH = 0x1,
    AGA_EQUIP_STOP = 0x2,
    AGA_UNEQUIP_START = 0x0,
    AGA_UNEQUIP_DETACH = 0x1,
    AGA_UNEQUIP_STOP = 0x2,
    AGA_CAST_START = 0x0,
    AGA_CAST_HIT = 0x1,
    AGA_CAST_STOP = 0x2,
  };

  enum ANIM_GROUP_SECTION
  {
    AGS_NONE = 0xFFFFFFFF,
    AGS_IDLE = 0x0,
    AGS_MOVEMENT = 0x1,
    AGS_LEFT_ARM = 0x2,
    AGS_TALKING = 0x3,
    AGS_WEAPON = 0x4,
    AGS_WEAPON_UP = 0x5,
    AGS_WEAPON_DOWN = 0x6,
    AGS_SPECIAL_IDLE = 0x7,
    ANIM_GROUP_SECTION_COUNT = 0x8,
    AGS_WHOLE_BODY = 0x14,
    AGS_UPPER_BODY = 0x15,
    ANIM_GROUP_SECTION_TOTAL_COUNT = 0x16,
    AGS_SKIP_ALL_BUT_SPECIAL_IDLE = 0x17,
  };

  class Animation
  {
    public:
      unsigned __int8 m_uFlags;
      TESObjectREFR *pActorRef;
      NiPointer<NiNode> pAnimRoot;
      NiNode *pAccumRoot;
      NiPoint3 movementDelta;
      NiPoint3 AccumRootTranslate;
      NiAVObject *pSoundPriorityBone[8];
      float m_fLooking;
      unsigned __int16 group[8];
      ANIM_GROUP_ACTION action[8];
      int loopCount[8];
      unsigned __int16 nextGroup[8];
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
      unsigned __int16 sQueuedReloadGroup;
      NiPointer<AnimIdle> spAnimIdle;
      NiPointer<AnimIdle> spAnimIdleQueued;
      NiPointer<AnimIdle> spAnimIdleFreeWhenInactiveA[2];
      BSSimpleList<IDLE_REPLAY_DELAY *> replayDelayList;
  };

  static_assert(sizeof(Animation) == 0x13C, "Animation has wrong size");
  
} // namespace CommonLib
