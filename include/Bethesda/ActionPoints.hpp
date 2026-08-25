#pragma once

namespace CommonLib {

  class ActionPoints
  {
    public:
      enum Action 
      {
        ACTION_ATTACK_UNARMED = 0x0,
        ACTION_ATTACK_ONE_HAND_MELEE = 0x1,
        ACTION_ATTACK_TWO_HAND_MELEE = 0x2,
        ACTION_ATTACK_PISTOL = 0x3,
        ACTION_ATTACK_RIFLE = 0x4,
        ACTION_ATTACK_HANDLE = 0x5,
        ACTION_ATTACK_LAUNCHER = 0x6,
        ACTION_ATTACK_GRENADE = 0x7,
        ACTION_ATTACK_MINE = 0x8,
        ACTION_RELOAD = 0x9,
        ACTION_CROUCH = 0xA,
        ACTION_STAND = 0xB,
        ACTION_SWITCH_WEAPON = 0xC,
        ACTION_TOGGLE_WEAPON_DRAWN = 0xD,
        ACTION_HEAL = 0xE,
        ACTION_PLAYER_VATS_DEATH = 0xF,
        ACTION_PLAYER_SPECIAL_WEAPON_ATTACK = 0x10,
        ACTION_PLAYER_SPECIAL_UNARMED_ATTACK = 0x11,
        ACTION_TARGET_KILL_SHOT = 0x12,
        ACTION_ATTACK_THROWN = 0x13,
        ACTION_PLAYER_SPECIAL_UNARMED_ATTACK_2 = 0x14,
        ACTION_PLAYER_SPECIAL_UNARMED_ATTACK_3 = 0x15,
        ACTION_COUNT = 0x16,
      };
  };

  static_assert(sizeof(ActionPoints) == 0x1, "ActionPoints has wrong size");
  
} // namespace CommonLib
