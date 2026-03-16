#pragma once
#include <cstdint>
#include "Bethesda/BSShaderAccumulator.hpp"
#include "Gamebryo/NiCamera.hpp"

class ShadowSceneLight;

class BSCubeMapCamera : public NiCamera
{
  public:
    BSCubeMapCamera();
    ~BSCubeMapCamera();

    enum etCubeMapType : std::int32_t
    {
      BSCMC_CUBEMAP = 0x0,
      BSCMC_6TEXTURES = 0x1,
      BSCMC_TILEDCUBE = 0x2,
      BSCMC_CUBEMAPMASK = 0x3,
    };

    BSCubeMapCamera::etCubeMapType eCubeMapType;
    NiPointer<BSRenderedTexture> spRenderedTexture[6];
    NiPointer<BSRenderedTexture> spRenderedCubeMap;
    ShadowSceneLight *pShadowLight;
    NiPointer<NiAVObject> spCubeMapScene;
    NiPointer<BSShaderAccumulator> spAccumulator;
};


static_assert(sizeof(BSCubeMapCamera) == 0x140, "BSCubeMapCamera has wrong size");
