#pragma once
#include <cstdint>
#include "Bethesda/BSSimpleList.hpp"
#include "Bethesda/MagicSystem.hpp"
#include "Bethesda/BSSoundHandle.hpp"

class ActiveEffect;
class MagicItem;
class MagicCaster;
class MagicTarget;
class EffectItem;
class TESBoundObject;
class MagicHitEffect;

class ActiveEffect
{
  public:
    ActiveEffect();
    virtual ~ActiveEffect();

    float fElapsedSeconds;
    MagicItem* pSpell;
    EffectItem* pEffect;
    bool bActive;
    bool bStarted;
    bool bFinished;
    bool bDone;
    bool bWornEnchantment;
    std::int32_t iFlags;
    float fMagnitude;
    float fDuration;
    MagicTarget* pTarget;
    MagicCaster* pCaster;
    MagicSystem::SpellType eSpellType;
    BSSoundHandle PersistentSound;
    TESBoundObject* pSource;
    BSSimpleList<MagicHitEffect*>* pHitEffects;
    MagicItem* pDisplacementSpell;
};

static_assert(sizeof(ActiveEffect) == 0x48, "ActiveEffect has wrong size");
