#pragma once
#include <cstdint>
#include "Types.hpp"
#include "Bethesda/TESEnchantableForm.hpp"
#include "Bethesda/TESImageSpaceModifiableForm.hpp"
#include "Bethesda/TESBoundObject.hpp"
#include "Bethesda/TESFullName.hpp"
#include "Bethesda/TESModel.hpp"
#include "Bethesda/BGSPreloadable.hpp"

class TESObjectLIGH;
class TESSound;
class BGSImpactDataSet;

class BGSExplosion : 
  public TESBoundObject, 
  public TESFullName, 
  public TESModel, 
  public TESEnchantableForm, 
  public BGSPreloadable, 
  public TESImageSpaceModifiableForm 
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
