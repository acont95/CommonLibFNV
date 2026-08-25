#pragma once

namespace CommonLib {

  class CachedValuesOwner
  {
    public:
      virtual float CalculateCachedRadius();
      virtual float CalculateCachedWidth();
      virtual float CalculateCachedLength();
      virtual float CalculateCachedForwardLength();
      virtual float CalculateCachedWeaponDPS();
      virtual float CalculateCachedMedicineEffectivenessMult();
      virtual float CalculateCachedSurvivalEffectivenessMult();
      virtual float CalculateCachedParalysis();
      virtual float CalculateCachedHealingRate();
      virtual float CalculateCachedEndurance();
      virtual float CalculateCachedPerceptionCondition();
      virtual float CalculateCachedEyeLevel();
      virtual int CalculateCachedActorAggression();
      virtual int CalculateCachedActorAssistance();
      virtual float CalculateCachedWalkSpeed();
      virtual float CalculateCachedRunSpeed();
      virtual bool CalculateCachedConditionPreventsRun();
  };

  static_assert(sizeof(CachedValuesOwner) == 0x4, "CachedValuesOwner has wrong size");
  
} // namespace CommonLib
