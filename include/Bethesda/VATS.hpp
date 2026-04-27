#pragma once
#include <cstdint>
#include "Bethesda/BSSimpleList.hpp"
#include "Bethesda/ShadowSceneLight.hpp"
#include "Gamebryo/NiPointer.hpp"

namespace CommonLib {

  class VATS_COMMAND;
  class BGSCameraShot;
  class Projectile;
  class TESIdleForm;
  class ImageSpaceModifierInstanceForm;
  class ImageSpaceModifierInstanceRB;
  class TESBoundObject;
  class ExtraDataList;

  class VATS
  {
    public:
      static VATS* GetVATSSingleton();

      enum VATS_MODE_ENUM : std::int32_t
      {
        VATS_MODE_NONE = 0x0,
        VATS_TARGET_SELECT = 0x1,
        VATS_MENU_MODE = 0x2,
        VATS_SCAN_MODE = 0x3,
        VATS_PLAYBACK = 0x4,
        VATS_MODE_COUNT = 0x5,
      };

      enum VATS_TILES : std::int32_t
      {
        VT_ACTION_QUEUE_LIST = 0x1,
        VT_ARROW_LEFT = 0x2,
        VT_ARROW_RIGHT = 0x3,
        VT_ACCEPT_BUTTON = 0x4,
        VT_RETURN_BUTTON = 0x5,
        VT_BODYPART_BUTTON = 0x6,
        VT_SELECT_BUTTON = 0x7,
        VT_RIGHT_BRACKET = 0x8,
        VT_ACTION_POINTS_BAR = 0x9,
        VT_ACTION_POINTS_BAR_GHOST = 0xA,
        VT_ACTION_POINTS_TEXT = 0xB,
        VT_ACTION_POINTS_LOW_TEXT = 0xC,
        VT_AMMO_TEXT = 0xD,
        VT_WEAPON_CONDITION_TEXT = 0xE,
        VT_WEAPON_CONDITION_METER = 0xF,
        VT_WEAPON_CONDITION_METER_BACKGROUND = 0x10,
        VT_LEFT_BRACKET = 0x11,
        VT_HEALTH_BAR = 0x12,
        VT_HIT_POINT_TEXT = 0x13,
        VT_COMPASS_GENERAL_ICONS = 0x14,
        VT_COMPASS_MARKER_ICONS = 0x15,
        VT_COMPASS_NPC_ICONS = 0x16,
        VT_COMPASS = 0x17,
        VT_ENEMY_HEALTH_BACKGROUND = 0x18,
        VT_ENEMY_HEALTH_BRACKET = 0x19,
        VT_ENEMY_HEALTH_METER = 0x1A,
        VT_ENEMY_HEALTH_METER_GHOST_2 = 0x1B,
        VT_ENEMY_HEALTH_METER_GHOST_1 = 0x1C,
        VT_ENEMY_HEALTH_NAME = 0x1D,
        VT_SPECIAL_ATTACK_BUTTON = 0x1E,
        VT_SPECIAL_ATTACK_BUTTON_2 = 0x1F,
        VT_NUM_TILES = 0x1F,
      };

      enum VATS_TARGET_TYPE : std::int32_t
      {
        VTT_NONE = 0x0,
        VTT_NPC = 0x1,
        VTT_DESTRUCTABLE_OBJECT = 0x2,
      };

      BSSimpleList<VATS_COMMAND *> commandList;
      VATS::VATS_MODE_ENUM eMode;
      BSSimpleList<BGSCameraShot *> *pCameraList;
      BGSCameraShot *pCamera;
      float fCameraTimer;
      float fCameraMinTimer;
      Projectile *pFirstProjectile;
      Projectile *pLastProjectile;
      TESIdleForm *pMeleeAttack;
      ImageSpaceModifierInstanceForm *pImagespaceMod;
      ImageSpaceModifierInstanceRB *pTransitionImagespaceMod;
      bool bAiming;
      NiPointer<ShadowSceneLight> spVATSLight;
      bool bFirstVatsAttack;
      int iKillCount;
      TESBoundObject *pUnEquipWeapon;
      ExtraDataList *pUnEquipExtra;
  };

  static_assert(sizeof(VATS) == 0x48, "VATS has wrong size");
  
} // namespace CommonLib
