#pragma once
#include <cstdint>
#include "Types.hpp"
#include "Bethesda/TESBoundObject.hpp"
#include "Bethesda/TESFullName.hpp"
#include "Bethesda/TESModelTextureSwap.hpp"
#include "Bethesda/TESIcon.hpp"
#include "Bethesda/BGSMessageIcon.hpp"
#include "Bethesda/TESValueForm.hpp"
#include "Bethesda/BGSClipRoundsForm.hpp"
#include "Bethesda/BGSDestructibleObjectForm.hpp"
#include "Bethesda/BGSPickupPutdownSounds.hpp"
#include "Bethesda/TESScriptableForm.hpp"

// TO DO
namespace CommonLib {

  class BGSProjectile;
  class TESAmmoEffect;

  class TESAmmo : 
    public TESBoundObject, 
    public TESFullName, 
    public TESModelTextureSwap, 
    public TESIcon, 
    public BGSMessageIcon, 
    public TESValueForm, 
    public BGSClipRoundsForm, 
    public BGSDestructibleObjectForm, 
    public BGSPickupPutdownSounds, 
    public TESScriptableForm
  {
    public:
      TESAmmo();
      virtual ~TESAmmo();

      struct AMMO_DATA
      {
        float fSpeed;
        unsigned __int8 cFlags;
      };

      struct AMMO_DATA_NV
      {
        unsigned __int8 cProjectilePerAmmo;
        BGSProjectile *pProjectileOverride;
        float fWeightOverride;
        TESForm *pAmmoConsumedObject;
        float fAmmoConsumedChance;
      };

      AMMO_DATA data;
      AMMO_DATA_NV NVdata;
      BSStringT<char> cDesc;
      BSStringT<char> cAbbrev;
      BSSimpleList<TESAmmoEffect *> pAmmoEffectList;
  };

  static_assert(sizeof(TESAmmo) == 0xDC, "TESAmmo has wrong size");
  
} // namespace CommonLib
