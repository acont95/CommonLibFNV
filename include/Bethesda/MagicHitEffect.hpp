#pragma once
#include "Bethesda/ActiveEffect.hpp"
#include "Bethesda/TESObjectREFR.hpp"
#include "Bethesda/BSTempEffect.hpp"

class MagicHitEffect : BSTempEffect
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
