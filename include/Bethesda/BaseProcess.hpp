#pragma once
#include "Bethesda/ActorPackage.hpp"

namespace CommonLib {

  class CachedValues;

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
      BaseProcess();
      virtual ~BaseProcess();

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

      ActorPackage CurrentPackage;
      float fSystemTimeClock;
      float fHourLastProcessed;
      unsigned int iDateLastProcessed;
      PROCESS_TYPE eLevel;
      CachedValues *pCachedValues;
  };

  static_assert(sizeof(BaseProcess) == 0x30, "BaseProcess has wrong size");
  
} // namespace CommonLib
