#pragma once
#include <cstdint>
#include "Types.hpp"
#include "Bethesda/DecalData.hpp"
#include "Bethesda/TESForm.hpp"
#include "Bethesda/TESModel.hpp"

class TESSound;
class BGSTextureSet;

class BGSImpactData : public TESForm, public TESModel
{
  public:
    BGSImpactData();
    ~BGSImpactData();

    enum ORIENTATION
    {
      ORIENT_SURFACE_NORMAL = 0x0,
      ORIENT_PROJ_VECTOR = 0x1,
      ORIENT_PROJ_REFLECT = 0x2,
      ORIENT_COUNT = 0x3,
    };

    struct IMPACT_DATA_DATA
    {
      float fEffectDuration;
      BGSImpactData::ORIENTATION eOrient;
      float fAngleThreshold;
      float fPlacementRadius;
      SOUND_LEVEL eSoundLevel;
      std::uint8_t cFlags;
    };

    BGSImpactData::IMPACT_DATA_DATA Data;
    BGSTextureSet *pDecalTextureSet;
    TESSound *pSound1;
    TESSound *pSound2;
    DecalData DData;
};

static_assert(sizeof(BGSImpactData) == 0x78, "BGSImpactData has wrong size");
