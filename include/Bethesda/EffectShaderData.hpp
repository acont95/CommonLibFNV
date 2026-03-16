#pragma once
#include <cstdint>
#include <d3d9.h>
#include "Gamebryo/NiPoint3.hpp"

class BGSDebris;

class EffectShaderData
{
  public:
    EffectShaderData();
    ~EffectShaderData();
  
    std::uint8_t cFlags;
    D3DBLEND eTextureBlendModeSource;
    D3DBLENDOP eTextureBlendOperation;
    D3DCMPFUNC eTextureZTestFunction;
    std::uint32_t iFillColor;
    float fFillAlphaFadeInTime;
    float fFillAlphaFullTime;
    float fFillAlphaFadeOutTime;
    float fFillAlphaPersistentPercent;
    float fFillAlphaPulseAmplitude;
    float fFillAlphaPulseFrequency;
    float fFillTextureUAnimSpeed;
    float fFillTextureVAnimSpeed;
    float fEdgeExponentValue;
    std::uint32_t iEdgeColor;
    float fEdgeAlphaFadeInTime;
    float fEdgeAlphaFullTime;
    float fEdgeAlphaFadeOutTime;
    float fEdgeAlphaPersistentPercent;
    float fEdgeAlphaPulseAmplitude;
    float fEdgeAlphaPulseFrequency;
    float fFillAlphaFullPercent;
    float fEdgeAlphaFullPercent;
    D3DBLEND eTextureBlendModeDest;
    D3DBLEND eParticleBlendModeSource;
    D3DBLENDOP eParticleBlendOperation;
    D3DCMPFUNC  eParticleZTestFunction;
    D3DBLEND eParticleBlendModeDest;
    float fParticleFadeInTime;
    float fParticleFullTime;
    float fParticleFadeOutTime;
    float fParticleFull;
    float fParticlePersistent;
    float fParticleLifetime;
    float fParticleLifeVar;
    float fParticleNormalSpeed;
    float fParticleNormalAcc;
    NiPoint3 ParticleVelocity;
    NiPoint3 ParticleAcceleration;
    float fParticleScale1;
    float fParticleScale2;
    float fParticleScale1Time;
    float fParticleScale2Time;
    std::uint32_t iParticleColor1;
    std::uint32_t iParticleColor2;
    std::uint32_t iParticleColor3;
    float fParticleColor1Alpha;
    float fParticleColor2Alpha;
    float fParticleColor3Alpha;
    float fParticleColor1Time;
    float fParticleColor2Time;
    float fParticleColor3Time;
    float fParticleNormalSpeedVar;
    float fParticleRotate;
    float fParticleRotateVar;
    float fParticleRotateSpeed;
    float fParticleRotateSpeedVar;
    BGSDebris* pAddonModels;
    float fAlphaTestStartTime;
    float fAlphaTestEndTime;
    float fAlphaTestStartValue;
    float fAlphaTestEndValue;
    float fAlphaEdgeWidth;
    std::uint32_t iAlphaEdgeColor;
    float fExplosionSpeed;
    std::uint32_t iParticleTextureCountX;
    std::uint32_t iParticleTextureCountY;
    float fAddOnFadeInTime;
    float fAddOnFadeOutTime;
    float fAddOnScaleStart;
    float fAddOnScaleEnd;
    float fAddOnScaleInTime;
    float fAddOnScaleOutTime;
};

static_assert(sizeof(EffectShaderData) == 0x134, "EffectShaderData has wrong size");
