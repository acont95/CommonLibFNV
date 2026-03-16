#pragma once
#include "Gamebryo/NiLight.hpp"

class TESObjectLIGH;

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
