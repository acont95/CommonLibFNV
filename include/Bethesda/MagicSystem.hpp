#pragma once
#include <cstdint>

namespace CommonLib {

  class MagicSystem {
    public:

      enum School
      {
        ALTERATION = 0x0,
        CONJURATION = 0x1,
        DESTRUCTION = 0x2,
        ILLUSION = 0x3,
        MYSTICISM = 0x4,
        RESTORATION = 0x5,
        SCHOOL_COUNT = 0x6,
      };

      enum SpellType
      {
        SPELL = 0x0,
        DISEASE = 0x1,
        POWER = 0x2,
        LESSER_POWER = 0x3,
        ABILITY = 0x4,
        POISON = 0x5,
        ENCHANTMENT = 0x6,
        POTION = 0x7,
        WORTCRAFT = 0x8,
        LEVELED_SPELL = 0x9,
        ADDICTION = 0xA,
        SPELL_TYPE_COUNT = 0xB,
      };

      enum FlareType
      {
        FLARE_NONE = 0x0,
        FLARE_FIRE = 0x1,
        FLARE_FROST = 0x2,
        FLARE_SHOCK = 0x4,
        FLARE_WEAPON = 0x8,
      };

      enum Range
      {
        SELF = 0x0,
        TOUCH = 0x1,
        TARGET = 0x2,
        RANGE_COUNT = 0x3,
      };

      enum CastingType
      {
        CAST_ONCE = 0x0,
        WHEN_USED = 0x1,
        WHEN_STRIKES = 0x2,
        CONSTANT_EFFECT = 0x3,
        CASTING_COUNT = 0x4,
      };

      enum ProjectileType
      {
        BALL = 0x0,
        BOLT = 0x1,
        SPRAY = 0x2,
        PROJECTILE_TYPE_COUNT = 0x4,
      };
  };

  static_assert(sizeof(MagicSystem) == 0x1, "MagicSystem has wrong size");
  
} // namespace CommonLib
