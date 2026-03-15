#pragma once
#include <cstdint>
#include "Bethesda/SunOcclusionTest.hpp"
#include "Bethesda/BSOcclusionQuery.hpp"
#include "Bethesda/BSTPersistentList.hpp"
#include "Bethesda/BSBatchRenderer.hpp"
#include "Bethesda/ShadowSceneNode.hpp"
#include "Bethesda/ShadowSceneLight.hpp"
#include "Bethesda/BSRenderedTexture.hpp"
#include "Bethesda/BSShaderManager.hpp"
#include "Bethesda/ReferenceVolume.hpp"
#include "Gamebryo/NiTPointerList.hpp"
#include "Gamebryo/NiGeometry.hpp"
#include "Gamebryo/NiTPointerMap.hpp"
#include "Gamebryo/NiTPointerAllocator.hpp"
#include "Gamebryo/NiCriticalSection.hpp"
#include "Gamebryo/NiAlphaAccumulator.hpp"

class BSShaderAccumulator : NiAlphaAccumulator
{
  public:
    BSShaderAccumulator();
    virtual ~BSShaderAccumulator();

    enum etAccumulationMode : __int32
    {
      BSSA_ACCUMNORMAL = 0x0,
      BSSA_ACCUMDEPTHMAP = 0x1,
      BSSA_ACCUMLOD = 0x2,
      BSSA_ACCUMNONE = 0x3,
    };

    enum WATER_SIDE : __int32
    {
      ABOVE_WATER = 0x0,
      BELOW_WATER = 0x1,
    };

    enum DepthTransformationEnum : __int32
    {
      VTRANS_DEFAULT = 0x0,
      VTRANS_SKINNED = 0x1,
      VTRANS_3XDEFAULT = 0x2,
      VTRANS_3XSKINNED = 0x3,
      VTRANS_COUNT = 0x4,
    };

    etAccumulationMode eAccumulationMode;
    bool bWorldGeometry;
    bool bCacheGeometry;
    bool bDoDepthPasses;
    unsigned int uiSunPixelCount;
    bool bWaitingForSunQueury;
    float fPercentSunOccludedStored;
    SunOcclusionTest pSunTests[3];
    bool bAccumulate;
    bool b1stPerson;
    bool bRenderNoShader;
    unsigned __int16 usQueryCount;
    unsigned __int16 usQuerySize;
    BSOcclusionQuery **ppOcclusionQuery;
    NiTPointerList<NiGeometry *> pVolumetricFogGeometry;
    BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *> pRenderedGeometryCache[4];
    BSTPersistentList<NiTPointerAllocator<unsigned int>,NiGeometry *> pRendered1stPersonGeometryCache[4];
    NiPointer<NiGeometry> spBoundTestGeometry;
    NiTPointerList<ReferenceVolume *> ReferenceVolumeList;
    unsigned int uiLastOcclusionRef;
    bool bLastOcclusionResult;
    NiColorA kSilhouetteColor;
    bool bWaterReflection;
    bool bWaterRefraction;
    bool bCellHasWater;
    bool bUnderWater;
    int iCurrentWaterHeight;
    bool bRenderDecals;
    struct BSInstanceRendering *pInstanceRenderer;
    BSBatchRenderer *pBatchRenderer[2];
    unsigned int *puicurrentPassA;
    int *picurrentBucketA;
    bool *pbcurrentFirstPassA;
    bool *pbcurrentActiveA;
    unsigned int uiBatchRendererCount;
    unsigned int uiBatchRendererPassCount;
    ShadowSceneNode *pActiveShadowSceneNode;
    NiPointer<BSRenderedTexture> spWaterFogRenderTarget;
    BSShaderManager::etRenderMode eRenderMode;
    NiPointer<ShadowSceneLight> spShadowLight;
    BSShaderProperty::RenderPass kAlphaRenderPass;
    NiTPointerMap<NiAVObject*, bool> kRoomSharedMap;
    std::uint8_t pad01[60];
    NiCriticalSection BSCPSharedCrit;
};

static_assert(sizeof(BSShaderAccumulator) == 0x280);
