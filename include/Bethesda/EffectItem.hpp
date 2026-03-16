#pragma once
#include "Bethesda/EffectItemData.hpp"
#include "Bethesda/TESCondition.hpp"

namespace CommonLib {

  class EffectSetting;

  class EffectItem 
  {
    public:
      EffectItem();
      ~EffectItem();

      EffectItemData data;
      EffectSetting *pEffectSetting;
      float fRawCost;
      TESCondition Conditions;
  };

  static_assert(sizeof(EffectItem) == 0x24, "EffectItem has wrong size");
  
} // namespace CommonLib
