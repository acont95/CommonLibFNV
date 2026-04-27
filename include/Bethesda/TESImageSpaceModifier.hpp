#pragma once
#include <cstdint>
#include "Bethesda/TESForm.hpp"
#include "Gamebryo/NiFloatInterpolator.hpp"
#include "Gamebryo/NiColorInterpolator.hpp"
#include "Gamebryo/NiPoint2.hpp"

namespace CommonLib {

  class TESSound;
  class NiLinFloatKey;
  class NiLinColorKey;

  class TESImageSpaceModifier : public TESForm
  {
    public:

      enum ImageSpaceModifierOperations
      {
        IMAOP_MULT = 0x0,
        IMAOP_ADD = 0x1,
        IMAOP_COUNT = 0x2,
      };

      enum ImageSpaceOpParameterEnum
      {
        IMAGESPACEOPPARAM_HDR_FIRST = 0x0,
        IMAGESPACEOPPARAM_HDR_EYE_ADAPT_SPEED = 0x0,
        IMAGESPACEOPPARAM_HDR_BLUR_RADIUS = 0x1,
        IMAGESPACEOPPARAM_HDR_SKIN_DIMMER = 0x2,
        IMAGESPACEOPPARAM_HDR_EMISSIVE_MULT = 0x3,
        IMAGESPACEOPPARAM_HDR_TARGET_LUM = 0x4,
        IMAGESPACEOPPARAM_HDR_UPPER_LUM_CLAMP = 0x5,
        IMAGESPACEOPPARAM_HDR_BRIGHT_SCALE = 0x6,
        IMAGESPACEOPPARAM_HDR_BRIGHT_CLAMP = 0x7,
        IMAGESPACEOPPARAM_HDR_LUM_RAMP_NO_TEX = 0x8,
        IMAGESPACEOPPARAM_HDR_LUM_RAMP_MIN = 0x9,
        IMAGESPACEOPPARAM_HDR_LUM_RAMP_MAX = 0xA,
        IMAGESPACEOPPARAM_HDR_SUNLIGHT_DIMMER = 0xB,
        IMAGESPACEOPPARAM_HDR_GRASS_DIMMER = 0xC,
        IMAGESPACEOPPARAM_HDR_TREE_DIMMER = 0xD,
        IMAGESPACEOPPARAM_HDR_LAST = 0xD,
        IMAGESPACEOPPARAM_BLOOM_FIRST = 0xE,
        IMAGESPACEOPPARAM_BLOOM_BLUR_RADIUS = 0xE,
        IMAGESPACEOPPARAM_BLOOM_ALPHA_ADD_INTERIOR = 0xF,
        IMAGESPACEOPPARAM_BLOOM_ALPHA_ADD_EXTERIOR = 0x10,
        IMAGESPACEOPPARAM_BLOOM_LAST = 0x10,
        IMAGESPACEOPPARAM_CINEMATIC_FIRST = 0x11,
        IMAGESPACEOPPARAM_CINEMATIC_SATURATION_VALUE = 0x11,
        IMAGESPACEOPPARAM_CINEMATIC_CONTRAST_AVG_LUM = 0x12,
        IMAGESPACEOPPARAM_CINEMATIC_CONTRAST_VALUE = 0x13,
        IMAGESPACEOPPARAM_CINEMATIC_BRIGHTNESS = 0x14,
        IMAGESPACEOPPARAM_CINEMATIC_LAST = 0x14,
        NUM_OP_PARAMS = 0x15,
      };

      struct ImageSpaceModifierData
      {
        bool bAnimatable;
        float fDuration;
        std::uint32_t ppuiKeySize[21][2];
        std::uint32_t uiTintColorKeySize;
        std::uint32_t uiBlurKeySize;
        std::uint32_t uiDoubleKeySize;
        std::uint32_t uiRadialBlurStrengthKeySize;
        std::uint32_t uiRadialBlurRampupKeySize;
        std::uint32_t uiRadialBlurStartKeySize;
        bool bUseTargetForRadialBlur;
        NiPoint2 RadialBlurCenter;
        std::uint32_t uiDepthOfFieldStrengthKeySize;
        std::uint32_t uiDepthOfFieldDistanceKeySize;
        std::uint32_t uiDepthOfFieldRangeKeySize;
        bool bUseTargetForDepthOfField;
        std::uint8_t ucDepthOfFieldMode;
        std::uint32_t uiRadialBlurRampDownKeySize;
        std::uint32_t uiRadialBlurDownStartKeySize;
        std::uint32_t uiFadeColorKeySize;
        std::uint32_t uiMotionBlurStrengthKeySize;
      };

      TESSound *pOutroSound;
      TESSound *pIntroSound;
      TESImageSpaceModifier::ImageSpaceModifierData Data;
      NiFloatInterpolator ppInterpolator[21][2];
      NiFloatInterpolator BlurInterpolator;
      NiFloatInterpolator DoubleInterpolator;
      NiColorInterpolator TintColorInterpolator;
      NiColorInterpolator FadeColorInterpolator;
      NiFloatInterpolator RadialBlurStrengthInterpolator;
      NiFloatInterpolator RadialBlurRampupInterpolator;
      NiFloatInterpolator RadialBlurStartInterpolator;
      NiFloatInterpolator RadialBlurRampDownInterpolator;
      NiFloatInterpolator RadialBlurDownStartInterpolator;
      NiFloatInterpolator DepthOfFieldStrengthInterpolator;
      NiFloatInterpolator DepthOfFieldDistanceInterpolator;
      NiFloatInterpolator DepthOfFieldRangeInterpolator;
      NiFloatInterpolator MotionBlurStrengthInterpolator;
      NiLinFloatKey* pppFloatKey[21][2];
      NiLinFloatKey* pBlurFloatKey;
      NiLinFloatKey* pDoubleFloatKey;
      NiLinColorKey* pTintColorKey;
      NiLinColorKey* pFadeColorKey;
      NiLinFloatKey* pRadialBlurStrengthFloatKey;
      NiLinFloatKey* pRadialBlurRampupFloatKey;
      NiLinFloatKey* pRadialBlurStartFloatKey;
      NiLinFloatKey* pRadialBlurRampDownFloatKey;
      NiLinFloatKey* pRadialBlurDownStartFloatKey;
      NiLinFloatKey* pDepthOfFieldStrengthFloatKey;
      NiLinFloatKey* pDepthOfFieldDistanceFloatKey;
      NiLinFloatKey* pDepthOfFieldRangeFloatKey;
      NiLinFloatKey* pMotionBlurStrengthFloatKey;
  };

  static_assert(sizeof(TESImageSpaceModifier) == 0x730, "TESImageSpaceModifier has wrong size");
  
} // namespace CommonLib
