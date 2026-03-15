#pragma once
#include "Bethesda/TESForm.hpp"
#include "Bethesda/TESTexture.hpp"
#include "Bethesda/TESSound.hpp"
#include "Bethesda/WaterShaderData.hpp"
#include "Bethesda/SpellItem.hpp"
#include "Bethesda/BGSPlaceableWater.hpp"
#include "Bethesda/TESAttackDamageForm.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiColorA.hpp"

class TESWaterForm : TESForm, TESFullName, TESAttackDamageForm
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
    unsigned __int8 cAlpha;
    unsigned __int8 cFlags;
    __declspec(align(4)) BSStringT<char> cMaterialID;
    TESSound *pWaterSound;
    TESWaterForm *pRemappedWaterForm;
    WaterShaderData Data;
    TESWaterForm *pWaterWeatherControl[3];
    int iCurrentTextureSelect01;
    int iCurrentTextureSelect02;
    unsigned int fFrequencyX;
    unsigned int fFrequencyY;
    int iOctaves;
    float fAmplitude;
    float fLacunarity;
    float fBias;
    float fGain;
    SpellItem *pSpellItem;
    NiPointer<NiTexture> spNoiseTexture;
    BGSPlaceableWater *pPlaceableAutoWater;
    BGSPlaceableWater *pPlaceableLODWater;
    int iRadiationDamage;
    int iHealthRestoration;
    bool bResetNoiseTexture;
};

static_assert(sizeof(TESWaterForm) == 0x194, "TESWaterForm has wrong size");
