#pragma once
#include <cstdint>
#include "Bethesda/TESBoundObject.hpp"
#include "Bethesda/TESFullName.hpp"
#include "Bethesda/TESModel.hpp"
#include "Bethesda/TESEnchantableForm.hpp"
#include "Bethesda/BGSPreloadable.hpp"
#include "Bethesda/TESImageSpaceModifiableForm.hpp"
#include "Bethesda/TESSound.hpp"
#include "Bethesda/TESObjectLIGH.hpp"
#include "Bethesda/BGSImpactDataSet.hpp"

class BGSExplosion : TESBoundObject, TESFullName, TESModel, TESEnchantableForm, BGSPreloadable, TESImageSpaceModifiableForm 
{
  public:
    BGSExplosion();
    ~BGSExplosion();

    struct BGSExplosionData
    {
      float fForce;
      float fDamage;
      float fRadius;
      TESObjectLIGH* pLight;
      TESSound* pSound1;
      std::uint32_t iFlags;
      float fImageSpaceRadius;
      BGSImpactDataSet* pImpactDataSet;
      TESSound* pSound2;
      float fRadiationRads;
      float fRadiationDissipationTime;
      float fRadiationRadius;
      SOUND_LEVEL eSoundLevel;
    };

    TESBoundObject* pImpactPlacedObject;
    BGSExplosionData Data;
};

static_assert(sizeof(BGSExplosion) == 0xA8, "BGSExplosion has wrong size");
