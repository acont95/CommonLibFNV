#pragma once
#include <cstdint>
#include "Bethesda/TESSound.hpp"
#include "Bethesda/TESBoundAnimObject.hpp"
#include "Bethesda/TESFullName.hpp"
#include "Bethesda/TESModelTextureSwap.hpp"
#include "Bethesda/TESIcon.hpp"
#include "Bethesda/BGSMessageIcon.hpp"
#include "Bethesda/TESScriptableForm.hpp"
#include "Bethesda/TESWeightForm.hpp"
#include "Bethesda/TESValueForm.hpp"
#include "Bethesda/BGSDestructibleObjectForm.hpp"
#include "Gamebryo/NiColor.hpp"

class TESObjectLIGH : 
    TESBoundAnimObject, 
    TESFullName, 
    TESModelTextureSwap, 
    TESIcon, 
    BGSMessageIcon, 
    TESScriptableForm, 
    TESWeightForm, 
    TESValueForm, 
    BGSDestructibleObjectForm
{
  public:
    TESObjectLIGH();
    virtual ~TESObjectLIGH();

    struct OBJ_LIGH
    {
      std::int32_t time;
      std::uint32_t radius;
      std::uint32_t color;
      std::uint32_t flags;
      float fFallOffExponent;
      float fFOV;
    };

    OBJ_LIGH data;
    float fFade;
    TESSound* m_pSound;
    NiColor EmittanceColor;
};

static_assert(sizeof(TESObjectLIGH) == 0xC8, "TESObjectLIGH has wrong size");
