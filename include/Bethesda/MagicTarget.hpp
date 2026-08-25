#pragma once
#include "Bethesda/BSSimpleList.hpp"

namespace CommonLib {

  class SpellDispelData;
  class MagicCaster;
  class MagicItem;
  class ActiveEffect;
  class TESObjectREFR;

  class MagicTarget
  {
    public:
      virtual bool AddTarget(MagicCaster*, MagicItem*, ActiveEffect*, bool);
      virtual TESObjectREFR* GetTargetStatsObject();
      virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList();
      virtual bool MagicTargetIsActor();
      virtual bool IsInvulnerable();
      virtual void EffectAdded(ActiveEffect*);
      virtual void EffectRemoved(ActiveEffect*);
      virtual void EffectReflected(MagicCaster*, ActiveEffect*);
      virtual void EffectAbsorbed(MagicCaster*, ActiveEffect*);
      virtual float CheckResistance(MagicCaster*, MagicItem*, ActiveEffect*);
      virtual bool CheckAbsorb(MagicCaster*, MagicItem*, ActiveEffect*, bool);
      virtual bool CheckReflect(MagicCaster*, MagicItem*, ActiveEffect*);

      bool bShowTargetStats;
      bool bUpdating;
      BSSimpleList<SpellDispelData*> PostUpdateDispelList;
  };

  static_assert(sizeof(MagicTarget) == 0x10, "MagicTarget has wrong size");

} // namespace CommonLib
