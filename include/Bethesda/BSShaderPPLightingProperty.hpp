#pragma once
#include <d3d9types.h>
#include "Bethesda/BSTextureSet.hpp"
#include "Bethesda/BSShaderProperty.hpp"
#include "Gamebryo/NiColorA.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiTexture.hpp"
#include "Gamebryo/NiTexturingProperty.hpp"

class BSShaderPPLightingProperty : BSShaderLightingProperty
{
  public:
    BSShaderPPLightingProperty();
    virtual ~BSShaderPPLightingProperty();

    class TangentSpaceData : public NiRefObject
    {
      public:
        TangentSpaceData();
        virtual ~TangentSpaceData();

        bool bOwnsMemory;
        NiPoint3 *pTangentExtraData;
        NiPoint3 *pBinormalExtraData;
    };

    class TextureEffectData : public NiRefObject
    {
      public:
        TextureEffectData();
        virtual ~TextureEffectData();

        NiPointer<NiTexture> spTexture;
        NiColorA CurrentFillColor;
        NiColorA CurrentRimColor;
        NiColorA FillColor;
        NiColorA RimColor;
        float fTextureUOffset;
        float fTextureVOffset;
        float fEdgeExponent;
        float fBoundDiameter;
        D3DBLEND eSrcBlendMode;
        D3DBLEND eDestBlendMode;
        D3DBLENDOP eBlendOperation;
        D3DCMPFUNC eZTestFunction;
        NiPointer<NiTexture> spBlockOutTexture;
        unsigned int iAlphaTest;
    };

    float fWaterDepthCameraOffset;
    float fGeomorphParam;
    NiColorA pHairTintColor;
    NiColorA LandBlendParamsA;
    NiPointer<BSTextureSet> spTextureSet;
    unsigned __int16 iTextureCount;
    NiPointer<NiTexture> *spTextures[7];
    unsigned __int8 *pSpecularExponent;
    unsigned __int16 usLandscapeTextures;
    bool *pbGlossMap;
    NiPointer<BSShaderPPLightingProperty::TangentSpaceData> spTangentSpaceData;
    float *pTextureSplatVertexData;
    NiTexturingProperty::ClampMode TextureClampMode;
    NiPointer<BSShaderPPLightingProperty::TextureEffectData> spTexEffectData;
    float fRefractionPower;
    int iRefractionFirePeriod;
    float fParallaxOccMaxPasses;
    float fParallaxOccScale;
    float fTerrainTexOffsetX;
    float fTerrainTexOffsetY;
    float fTerrainTexFade;
    float fTerrainDetailTexScale;
    BSShaderProperty::RenderPass *pRenderDepthPass;
};

static_assert(sizeof(BSShaderPPLightingProperty) == 0x108, "BSShaderPPLightingProperty has wrong size");
