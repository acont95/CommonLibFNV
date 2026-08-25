#pragma once
#include <cstdint>
#include "Bethesda/MagicItem.hpp"

namespace CommonLib {

  class MagicLight;
  class SpellItem;
  class MagicItem;
  class MagicTarget;
  class TESBoundObject;
  class NiNode;
  class ActiveEffect;
  class EffectItem;

  class MagicCaster
  {
    public:
      virtual ~MagicCaster();

      enum State
      {
        NO_SPELL = 0x0,
        AIM = 0x1,
        CAST = 0x2,
        RELEASE = 0x3,
        FIND_TARGETS = 0x4,
        ERR_SPELL_DISABLED = 0x5,
        ERR_ALREADY_CASTING = 0x6,
        ERR_CANNOT_CAST = 0x7,
      };

      virtual void CastAbility(SpellItem*, bool);
      virtual void CastAddiction(SpellItem*, bool);
      virtual void CastRadiation(SpellItem*, bool);
      virtual void CastSpellImmediate(MagicItem*, bool, MagicTarget*, float, bool);
      virtual void TransferDisease(SpellItem*, MagicTarget*, bool);
      virtual void CastWornEnchantment(MagicItem*, TESBoundObject*, bool);
      virtual MagicTarget* GetTouchTarget();
      virtual void StartAim();
      virtual void StartCast();
      virtual void SpellCast(MagicItem*, bool);
      virtual bool CheckCast(MagicItem*, float*, MagicItem::CannotCastReason*, bool);
      virtual TESObjectREFR* GetCasterStatsObject();
      virtual NiNode* GetMagicNode();
      virtual MagicItem* GetCurrentSpell();
      virtual bool TargetSelf(ActiveEffect*);
      virtual float GetMagicEffectivenessModifier(bool, float);
      virtual void SetCurrentSpell(MagicItem*);
      virtual MagicTarget* GetDesiredTarget();
      virtual void SetDesiredTarget(MagicTarget*);
      virtual ActiveEffect* CreateActiveEffect(MagicItem*, EffectItem*, TESBoundObject*);

      MagicLight *pLight;
      MagicCaster::State eState;
  };

  static_assert(sizeof(MagicCaster) == 0xC, "MagicCaster has wrong size");
  
} // namespace CommonLib
