#pragma once
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiNode.hpp"
#include "Gamebryo/NiLight.hpp"
#include "Bethesda/TESObjectLIGH.hpp"

class MagicLight
{
  public:
    MagicLight();
    ~MagicLight();

    struct REFR_LIGHT
    {
      NiPointer<NiLight> spLight;
      float fWantDimmer;
    };

    NiPointer<NiNode> pParent;
    TESObjectLIGH *pLightObject;
    REFR_LIGHT LightData;
    float fFadeTimer;
    float fFadeTargetTime;
    bool bFadeIn;
};

static_assert(sizeof(MagicLight) == 0x1C, "MagicLight has wrong size");
