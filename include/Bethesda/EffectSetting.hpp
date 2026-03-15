#pragma once
#include "Bethesda/BSSimpleList.hpp"
#include "Bethesda/ActorValue.hpp"
#include "Bethesda/TESObjectLIGH.hpp"
#include "Bethesda/TESEffectShader.hpp"
#include "Bethesda/TESSound.hpp"
#include "Bethesda/TESForm.hpp"
#include "Bethesda/TESModel.hpp"
#include "Bethesda/TESDescription.hpp"
#include "Bethesda/TESFullName.hpp"
#include "Bethesda/TESIcon.hpp"
#include "Bethesda/EffectArchetypes.hpp"

class EffectSetting : TESForm, TESModel, TESDescription, TESFullName, TESIcon
{
  public:
    EffectSetting();
    ~EffectSetting();

    struct EffectSettingData
    {
      unsigned int iFlags;
      float fBaseCost;
      TESForm* pAssociatedItem;
      ActorValue::Index iAssociatedSkill;
      ActorValue::Index iResistVariable;
      __int16 iNumCounterEffects;
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
    int iEffectLoadedCount;
    int iAssociatedItemLoadedCount;
};

static_assert(sizeof(EffectSetting) == 0xB0, "EffectSetting has wrong size");
