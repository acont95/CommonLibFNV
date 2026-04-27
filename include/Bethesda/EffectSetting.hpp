#pragma once
#include <cstdint>
#include "Bethesda/TESModel.hpp"
#include "Bethesda/TESForm.hpp"
#include "Bethesda/TESFullName.hpp"
#include "Bethesda/TESIcon.hpp"
#include "Bethesda/TESDescription.hpp"
#include "Bethesda/EffectArchetypes.hpp"

namespace CommonLib {

  class TESObjectLIGH;
  class TESEffectShader;
  class TESSound;

  class EffectSetting : 
    public TESForm, 
    public TESModel, 
    public TESDescription, 
    public TESFullName, 
    public TESIcon
  {
    public:

      struct EffectSettingData
      {
        std::uint32_t iFlags;
        float fBaseCost;
        TESForm* pAssociatedItem;
        ActorValue::Index iAssociatedSkill;
        ActorValue::Index iResistVariable;
        std::int16_t iNumCounterEffects;
        TESObjectLIGH *pLight;
        float fSpeed;
        TESEffectShader* pEffectShader;
        TESEffectShader* pEnchantEffect;
        TESSound* pCastSound;
        TESSound* pBoltSound;
        TESSound* pHitSound;
        TESSound* pAreaSound;
        float fCEEnchantFactor;
        float fCEBarterFactor;
        EffectArchetypes::ArchetypeID eArchetype;
        ActorValue::Index eAssociatedActorValue;
      };

      bool (__cdecl *pFilterValidationFunction)(EffectSetting*, void*);
      void *pFilterValidationItem;
      EffectSetting::EffectSettingData data;
      BSSimpleList<EffectSetting*> counterEffects;
      std::int32_t iEffectLoadedCount;
      std::int32_t iAssociatedItemLoadedCount;
  };

  static_assert(sizeof(EffectSetting) == 0xB0, "EffectSetting has wrong size");
  
} // namespace CommonLib
