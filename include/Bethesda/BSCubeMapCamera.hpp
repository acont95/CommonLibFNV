#pragma once
#include "Bethesda/BSCubeMapCamera.hpp"
#include "Bethesda/BSRenderedTexture.hpp"
#include "Bethesda/BSShaderAccumulator.hpp"
#include "Bethesda/ShadowSceneLight.hpp"
#include "Gamebryo/NiCamera.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiAVObject.hpp"

class BSCubeMapCamera : NiCamera
{
  public:
    BSCubeMapCamera();
    ~BSCubeMapCamera();

    enum etCubeMapType : __int32
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
