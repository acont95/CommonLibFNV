#pragma once
#include <cstdint>
#include "Bethesda/BSShaderProperty.hpp"
#include "Gamebryo/NiTPointerListSingleThread.hpp"

class BSShaderLightingProperty : public BSShaderProperty
{
  public:
    BSShaderLightingProperty();
    virtual ~BSShaderLightingProperty();

    enum etConstantIndex : std::int32_t
    {
      SLP_SC_AMBIENT = 0x0,
      SLP_SC_LIGHTCOLOR = 0x1,
      SLP_SC_LIGHTPOSITION = 0xB,
      SLP_SC_LIGHTDIRECTION = 0x13,
      SLP_SC_LIGHTRADIUS = 0x13,
      SLP_SC_EMITTANCECOLOR = 0x1B,
      SLP_SC_FOGPARAM = 0x1C,
      SLP_SC_FOGCOLOR = 0x1D,
      SLP_SC_EYEPOSITION = 0x1E,
      SLP_SC_EYEDIRECTION = 0x1F,
      SLP_SC_EYERIGHT = 0x20,
      SLP_SC_TOGGLES = 0x21,
      SLP_SC_HIGHDETAILRANGE = 0x22,
      SLP_SC_STBBCOLORCONSTANTS = 0x23,
      SLP_SC_LODTEXPARAMS = 0x24,
      SLP_SC_COUNT = 0x25,
    };

    enum etLightType : std::int32_t
    {
      SLP_LT_NONE = 0x0,
      SLP_LT_DIR = 0x1,
      SLP_LT_POINT = 0x2,
    };

    NiTPointerListSingleThread<ShadowSceneLight*> lLightList;
    float fForcedDarkness;
    std::uint32_t uiReferenceID;
    bool bLightListChanged;
    void* kLightListFence;
};

static_assert(sizeof(BSShaderLightingProperty) == 0x7C);
