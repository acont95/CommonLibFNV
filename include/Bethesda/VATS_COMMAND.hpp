#pragma once
#include <cstdint>
#include "Bethesda/ActionPoints.hpp"
#include "Bethesda/ActorValue.hpp"

namespace CommonLib {

  class TESObjectREFR;
  class HitData;

  class VATS_COMMAND
  {
    public:

      ActionPoints::Action eAction;
      bool bSuccess;
      bool bIronSights;
      bool bStranger;
      bool bParalyzingPalm;
      std::uint8_t cFireShots;
      std::uint8_t cFakeFireShots;
      TESObjectREFR *pTarget;
      ActorValue::Index eLimb;
      HitData *pHitData;
      float fTotalDamage;
      float fCumulativeDamage;
      float fActionPoints;
      bool bMissFortune;
  };

  static_assert(sizeof(VATS_COMMAND) == 0x28, "VATS_COMMAND has wrong size");
  
} // namespace CommonLib
