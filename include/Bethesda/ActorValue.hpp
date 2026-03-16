#pragma once
#include <cstdint>

namespace CommonLib {

  class ActorValueInfo;

  class ActorValue
  {
    public:
      ActorValue();
      ~ActorValue();

      enum Index 
      {
        AGGRESSION = 0x0,
        CONFIDENCE = 0x1,
        ENERGY = 0x2,
        RESPONSIBILITY = 0x3,
        MOOD = 0x4,
        STRENGTH = 0x5,
        PERCEPTION = 0x6,
        ENDURANCE = 0x7,
        CHARISMA = 0x8,
        INTELLIGENCE = 0x9,
        AGILITY = 0xA,
        LUCK = 0xB,
        ACTION_POINTS = 0xC,
        CARRY_WEIGHT = 0xD,
        CRITICAL_CHANCE = 0xE,
        HEALING_RATE = 0xF,
        HEALTH = 0x10,
        MELEE_DAMAGE = 0x11,
        DAMAGE_RESISTANCE = 0x12,
        POISON_RESISTANCE = 0x13,
        RADIATION_RESISTANCE = 0x14,
        SPEED_MULT = 0x15,
        FATIGUE = 0x16,
        KARMA = 0x17,
        EXPERIENCE_POINTS = 0x18,
        PERCEPTION_CONDITION = 0x19,
        ENDURANCE_CONDITION = 0x1A,
        LEFT_ATTACK_CONDITION = 0x1B,
        RIGHT_ATTACK_CONDITION = 0x1C,
        LEFT_MOBILITY_CONDITION = 0x1D,
        RIGHT_MOBILITY_CONDITION = 0x1E,
        BRAIN_CONDITION = 0x1F,
        BARTER = 0x20,
        BIG_GUNS = 0x21,
        ENERGY_WEAPONS = 0x22,
        EXPLOSIVES = 0x23,
        LOCKPICK = 0x24,
        MELEE_WEAPONS = 0x26,
        REPAIR = 0x27,
        SCIENCE = 0x28,
        SMALL_GUNS = 0x29,
        SNEAK = 0x2A,
        SPEECH = 0x2B,
        SURVIVAL = 0x2C,
        UNARMED = 0x2D,
        INVENTORY_WEIGHT = 0x2E,
        PARALYSIS = 0x2F,
        NIGHT_EYE_BONUS = 0x32,
        FIRE_RESISTANCE = 0x34,
        WATER_BREATHING = 0x35,
        RADIATION_RADS = 0x36,
        BLOODY_MESS = 0x37,
        UNARMED_DAMAGE = 0x38,
        ASSISTANCE = 0x39,
        ELECTRICAL_RESISTANCE = 0x3A,
        FROST_RESISTANCE = 0x3B,
        ENERGY_RESISTANCE = 0x3C,
        EMP_RESISTANCE = 0x3D,
        VARIABLE_01 = 0x3E,
        VARIABLE_02 = 0x3F,
        VARIABLE_03 = 0x40,
        VARIABLE_04 = 0x41,
        VARIABLE_05 = 0x42,
        VARIABLE_06 = 0x43,
        VARIABLE_07 = 0x44,
        VARIABLE_08 = 0x45,
        VARIABLE_09 = 0x46,
        VARIABLE_10 = 0x47,
        IGNORE_CRIPPLED_LIMBS = 0x48,
        DEHYDRATION = 0x49,
        HUNGER = 0x4A,
        SLEEPDEPREVATION = 0x4B,
        DAMAGE_THRESHOLD = 0x4C,
        ACTOR_VALUE_COUNT = 0x4D,
        AI_ATTRIBUTE_START = 0x0,
        ATTRIBUTE_START = 0x5,
        ACTOR_VALUE_START = 0x0,
        DERIVED_ATTRIBUTE_START = 0xC,
        CONDITION_START = 0x19,
        SKILL_START = 0x20,
        INT_START = 0x2E,
        VARIABLE_START = 0x3E,
        AI_ATTRIBUTE_END = 0x5,
        ATTRIBUTE_END = 0xC,
        CONDITION_END = 0x20,
        DERIVED_ATTRIBUTE_END = 0x20,
        SKILL_END = 0x2E,
        INT_END = 0x3E,
        VARIABLE_END = 0x4C,
        ATTRIBUTE_COUNT = 0x7,
        DERIVED_ATTRIBUTE_COUNT = 0x14,
        SKILL_COUNT = 0xE,
        AI_ATTRIBUTE_COUNT = 0x5,
        CONDITION_COUNT = 0x7,
        INT_COUNT = 0x10,
        VALUE_NONE = 0xFFFFFFFF,
        SKILL_NONE = 0xFFFFFFFF,
        ATTRIBUTE_NONE = 0xFFFFFFFF,
      };

      enum Section
      {
        ATTRIBUTE = 0x0,
        DERIVED_ATTRIBUTE = 0x1,
        SKILL = 0x2,
        AI_ATTRIBUTE = 0x3,
        CONDITION = 0x4,
        INT_VALUE = 0x5,
        RESISTANCE = 0x6,
        SECTION_COUNT = 0x8,
      };

      enum Flags
      {
        FAST_MODIFIER = 0x1,
        CREATURE_MAPPED = 0x2,
        EFFECT_SKILL = 0x4,
        MAX_TEN = 0x8,
        MAX_ONE_HUNDRED = 0x10,
        DAMAGE_MIN_ZERO = 0x20,
        DERIVED_PLUS_BASE = 0x40,
        DERIVED_IF_AUTOCALC = 0x80,
        ENUMERATION = 0x100,
        DAMAGE_IS_POSITIVE = 0x200,
        COMBAT_SKILL = 0x400,
        DERIVED_ALWAYS = 0x800,
        CREATURE_NOT_DERIVED = 0x1000,
        DEPRECATED = 0x2000,
        NO_SCRIPT_MODAV = 0x4000,
        MIN_ONE = 0x8000,
      };

      ActorValueInfo* pActorValueInfo[77];
  };

  static_assert(sizeof(ActorValue) == 0x134, "ActorValue has wrong size");
  
} // namespace CommonLib
