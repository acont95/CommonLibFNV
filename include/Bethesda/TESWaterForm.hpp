#pragma once
#include <cstdint>
#include "Bethesda/TESForm.hpp"
#include "Bethesda/TESTexture.hpp"
#include "Bethesda/WaterShaderData.hpp"
#include "Bethesda/TESAttackDamageForm.hpp"
#include "Bethesda/TESFullName.hpp"
#include "Bethesda/BSRenderedTexture.hpp"
#include "Gamebryo/NiColorA.hpp"

namespace CommonLib {

  class TESSound;
  class SpellItem;
  class BGSPlaceableWater;

  class TESWaterForm : public TESForm, public TESFullName, public TESAttackDamageForm
  {
    public:
      TESWaterForm();
      virtual ~TESWaterForm();

      bool bNeedUpdate;
      NiPointer<BSRenderedTexture> spNoiseNormalMap;
      NiColorA fTexScroll0;
      NiColorA fTexScroll1;
      NiColorA fTexScroll2;
      TESTexture NoiseTexture;
      std::uint8_t cAlpha;
      std::uint8_t cFlags;
      __declspec(align(4)) BSStringT<char> cMaterialID;
      TESSound *pWaterSound;
      TESWaterForm *pRemappedWaterForm;
      WaterShaderData Data;
      TESWaterForm *pWaterWeatherControl[3];
      std::int32_t iCurrentTextureSelect01;
      std::int32_t iCurrentTextureSelect02;
      std::uint32_t fFrequencyX;
      std::uint32_t fFrequencyY;
      std::int32_t iOctaves;
      float fAmplitude;
      float fLacunarity;
      float fBias;
      float fGain;
      SpellItem *pSpellItem;
      NiPointer<NiTexture> spNoiseTexture;
      BGSPlaceableWater *pPlaceableAutoWater;
      BGSPlaceableWater *pPlaceableLODWater;
      std::int32_t iRadiationDamage;
      std::int32_t iHealthRestoration;
      bool bResetNoiseTexture;
  };

  static_assert(sizeof(TESWaterForm) == 0x194, "TESWaterForm has wrong size");
  
} // namespace CommonLib
