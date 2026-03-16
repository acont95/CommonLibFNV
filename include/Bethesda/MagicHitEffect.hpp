#pragma once
#include "Bethesda/BSTempEffect.hpp"

namespace CommonLib {

  class ActiveEffect;
  class TESObjectREFR;

  class MagicHitEffect : public BSTempEffect
  {
    public:
      MagicHitEffect();
      ~MagicHitEffect();

      ActiveEffect *pEffect;
      TESObjectREFR *pTarget;
      float fAge;
      bool bFinished;
  };

  static_assert(sizeof(MagicHitEffect) == 0x28, "MagicHitEffect has wrong size");
  
} // namespace CommonLib
