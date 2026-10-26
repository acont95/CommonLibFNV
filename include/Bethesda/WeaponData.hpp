#pragma once

namespace CommonLib {

  class TESObjectWEAP;

  class WeaponData
  {
    public:
      TESObjectWEAP *pWeapon;
      float fCondition;
      float fDamagePerSecond;
      float fAbsoluteMaxRange;
      bool bInRange;
  };

  static_assert(sizeof(WeaponData) == 0x14, "WeaponData has wrong size");
  
} // namespace CommonLib
