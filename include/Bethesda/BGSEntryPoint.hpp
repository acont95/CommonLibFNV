#pragma once
#include <cstdint>

namespace CommonLib {

  class BGSEntryPoint 
  {
    public:
      enum ENTRY_POINT
      {
        CALCULATE_WEAPON_DAMAGE = 0x0,
        CALCULATE_CRITICAL_HIT_CHANCE = 0x1,
        CALCULATE_CRITICAL_HIT_DAMAGE = 0x2,
        CALCULATE_WEAPON_ATTACK_AP_COST = 0x3,
        CALCULATE_MINE_EXPLODE_CHANCE = 0x4,
        ADJUST_RANGE_PENALTY = 0x5,
        ADJUST_LIMB_DAMAGE = 0x6,
        CALCULATE_WEAPON_RANGE = 0x7,
        CALCULATE_TO_HIT_CHANCE = 0x8,
        ADJUST_EXPERIENCE_POINTS = 0x9,
        ADJUST_GAINED_SKILL_POINTS = 0xA,
        ADJUST_BOOK_SKILL_POINTS = 0xB,
        MODIFY_RECOVERED_HEALTH = 0xC,
        CALCULATE_INVENTORY_AP_COST = 0xD,
        GET_DISPOSITION = 0xE,
        GET_SHOULD_ATTACK = 0xF,
        GET_SHOULD_ASSIST = 0x10,
        CALCULATE_BUY_PRICE = 0x11,
        GET_BAD_KARMA = 0x12,
        GET_GOOD_KARMA = 0x13,
        IGNORE_LOCKED_TERMINAL = 0x14,
        ADD_LEVELED_LIST_ON_DEATH = 0x15,
        GET_MAX_CARRY_WEIGHT = 0x16,
        MODIFY_ADDICTION_CHANCE = 0x17,
        MODIFY_ADDICTION_DURATION = 0x18,
        MODIFY_POSITIVE_CHEM_DURATION = 0x19,
        ADJUST_DRINKING_RADIATION = 0x1A,
        ACTIVATE = 0x1B,
        MYSTERIOUS_STRANGER = 0x1C,
        HAS_PARALYZING_PALM = 0x1D,
        HACKING_SCIENCE_BONUS = 0x1E,
        IGNORE_RUNNING_DURING_DETECTION = 0x1F,
        IGNORE_BROKEN_LOCK = 0x20,
        HAS_CONCENTRATED_FIRE = 0x21,
        CALCULATE_GUN_SPREAD = 0x22,
        PLAYER_KILL_AP_REWARD = 0x23,
        MODIFY_ENEMY_CRITICAL_HIT_CHANCE = 0x24,
        RELOAD_SPEED_ENTRY = 0x25,
        EQUIP_SPEED_ENTRY = 0x26,
        ACTION_POINT_REGENERATION_ENTRY = 0x27,
        ACTION_POINT_COST_MODIFIER_ENTRY = 0x28,
        MISS_FORTUNE_ENTRY = 0x29,
        RUN_SPEED_MODIFIER = 0x2A,
        ATTACK_SPEED_MODIFIER = 0x2B,
        RADIATION_INGESTIBLE_BONUS = 0x2C,
        HAS_PIP_HACKER = 0x2D,
        HAS_MELTDOWN = 0x2E,
        SEE_ENEMY_HEALTH = 0x2F,
        HAS_JURY_RIGGING = 0x30,
        REDUCE_THREAT_RANGE = 0x31,
        REDUCE_THREAT_MODIFIER = 0x32,
        HAS_ALWAYS_FAST_TRAVEL = 0x33,
        KNOCKDOWN_CHANCE = 0x34,
        WEAPON_HANDLING_STRENGTH_BONUS = 0x35,
        AIM_MOVEMENT_MODIFIER = 0x36,
        HAS_LIGHT_ITEMS_WEIGH_NOTHING = 0x37,
        ADJUST_DAMAGE_THRESHOLD_DEFENDER = 0x38,
        MODIFY_CHANCE_FOR_AMMO_ITEM = 0x39,
        ADJUST_DAMAGE_THRESHOLD_ATTACKER = 0x3A,
        THROWING_VELOCITY_MODIFIER = 0x3B,
        CHANCE_FOR_ITEM_ON_FIRE = 0x3C,
        HAS_UNARMED_FORWARD_POWER_ATTACK = 0x3D,
        HAS_UNARMED_BACKWARD_POWER_ATTACK = 0x3E,
        HAS_CROUCHED_POWER_ATTACK = 0x3F,
        HAS_COUNTER_ATTACK = 0x40,
        HAS_UNARMED_LEFT_POWER_ATTACK = 0x41,
        HAS_UNARMED_RIGHT_POWER_ATTACK = 0x42,
        MODIFY_VATS_HELPER_CHANCE = 0x43,
        MODIFY_DAMAGE_TO_ITEMS = 0x44,
        HAS_IMPROVED_DETECTION = 0x45,
        HAS_IMPROVED_SPOTTING = 0x46,
        HAS_ITEM_DETECTION = 0x47,
        ADJUST_EXPLOSION_RADIUS = 0x48,
        NOT_YET_IMPLEMENTED = 0x49,
        ENTRY_POINT_COUNT = 0x4A,
      };

      struct EntryPointParameter
      {
        char *pParameterName;
      };

      struct EntryPointParameters
      {
        std::uint8_t cCount;
        EntryPointParameter *pParameters;
      };

      struct EntryPoint
      {
        char *pEntryPointName;
        BGSEntryPoint::EntryPointParameters FilterParameters;
        std::uint8_t cFunctionType;
      };

  };

  static_assert(sizeof(BGSEntryPoint) == 0x1, "BGSEntryPoint has wrong size");
  
} // namespace CommonLib
