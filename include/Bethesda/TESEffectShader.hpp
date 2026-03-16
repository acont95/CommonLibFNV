#pragma once
#include "Bethesda/TESForm.hpp"
#include "Bethesda/EffectShaderData.hpp"
#include "Bethesda/TESTexture.hpp"

namespace CommonLib {

  class TESEffectShader : public TESForm
  {
    public:
      TESEffectShader();
      ~TESEffectShader();

      EffectShaderData Data;
      TESTexture TextureShaderTexture;
      TESTexture ParticleShaderTexture;
      TESTexture BlockOutTexture;
  };

  static_assert(sizeof(TESEffectShader) == 0x170, "TESEffectShader has wrong size");
  
} // namespace CommonLib
