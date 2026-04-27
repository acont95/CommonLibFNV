#pragma once
#include <cstdint>
#include "Bethesda/ActorValue.hpp"
#include "Bethesda/ActiveEffect.hpp"

namespace CommonLib {

  class MagicCaster;
  class MagicItem;
  class EffectItem;

  class EffectArchetypes
  {
    public:

      enum ArchetypeID
      {
        ARCHETYPE_NONE = 0xFFFFFFFF,
        ARCHETYPE_START = 0x0,
        VALUE_MODIFIER = 0x0,
        SCRIPT = 0x1,
        DISPEL = 0x2,
        CURE_DISEASE = 0x3,
        ABSORB = 0x4,
        SHIELD = 0x5,
        CALM = 0x6,
        DEMORALIZE = 0x7,
        FRENZY = 0x8,
        COMMAND_CREATURE = 0x9,
        COMMAND_HUMANOID = 0xA,
        INVISIBILITY = 0xB,
        CHAMELEON = 0xC,
        LIGHT = 0xD,
        DARKNESS = 0xE,
        NIGHT_EYE = 0xF,
        LOCK = 0x10,
        OPEN = 0x11,
        BOUND_ITEM = 0x12,
        SUMMON_CREATURE = 0x13,
        DETECT_LIFE = 0x14,
        TELEKINESIS = 0x15,
        DISINTEGRATE_ARMOR = 0x16,
        DISINTEGRATE_WEAPON = 0x17,
        PARALYZE = 0x18,
        REANIMATE = 0x19,
        SOUL_TRAP = 0x1A,
        TURN_UNDEAD = 0x1B,
        SUN_DAMAGE = 0x1C,
        VAMPIRISM = 0x1D,
        CURE_PARALYSIS = 0x1E,
        CURE_ADDICTION = 0x1F,
        CURE_POISON = 0x20,
        CONCUSSION = 0x21,
        VALUE_AND_PARTS = 0x22,
        LIMB_CONDITION = 0x23,
        TURBO = 0x24,
        ARCHETYPE_COUNT = 0x25,
      };

      enum ArchetypeFlag
      {
        ASSOCIATED_ACTORVALUE = 0x2,
        ASSOCIATED_CREATURE = 0x4,
        ASSOCIATED_NPC = 0x8,
        ASSOCIATED_WEAPON = 0x10,
        ASSOCIATED_ARMOR = 0x20,
        ASSOCIATED_SCRIPT = 0x40,
      };

      struct ArchetypeDef
      {
        const char *pcName;
        ActiveEffect *(__cdecl *pInstantiateFunction)(MagicCaster*, MagicItem*, EffectItem*);
        std::uint32_t iFlags;
        ActorValue::Index iFixedActorValue;
      };

  };
  
} // namespace CommonLib
