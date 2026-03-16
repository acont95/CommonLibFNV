#pragma once
#include <cstdint>
#include "Bethesda/SunOcclusionTest.hpp"
#include "Bethesda/BSTPersistentList.hpp"
#include "Bethesda/BSShaderManager.hpp"
#include "Bethesda/BSShaderProperty.hpp"
#include "Bethesda/BSRenderedTexture.hpp"
#include "Gamebryo/NiTPointerMap.hpp"
#include "Gamebryo/NiCriticalSection.hpp"
#include "Gamebryo/NiAlphaAccumulator.hpp"
#include "Gamebryo/NiColorA.hpp"
#include "Gamebryo/NiAVObject.hpp"

class BSOcclusionQuery;
class BSBatchRenderer;
class ShadowSceneNode;
class ReferenceVolume;

class BSShaderAccumulator : public NiAlphaAccumulator
{
  public:
    BSShaderAccumulator();
    virtual ~BSShaderAccumulator();

    enum etAccumulationMode
    {
      BSSA_ACCUMNORMAL = 0x0,
      BSSA_ACCUMDEPTHMAP = 0x1,
      BSSA_ACCUMLOD = 0x2,
      BSSA_ACCUMNONE = 0x3,
    };

    enum WATER_SIDE
    {
      ABOVE_WATER = 0x0,
      BELOW_WATER = 0x1,
    };

    enum DepthTransformationEnum
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
    std::uint32_t uiSunPixelCount;
    bool bWaitingForSunQueury;
    float fPercentSunOccludedStored;
    SunOcclusionTest pSunTests[3];
    bool bAccumulate;
    bool b1stPerson;
    bool bRenderNoShader;
    std::uint16_t usQueryCount;
    std::uint16_t usQuerySize;
    BSOcclusionQuery **ppOcclusionQuery;
    NiTPointerList<NiGeometry *> pVolumetricFogGeometry;
    BSTPersistentList<NiTPointerAllocator<std::uint32_t>,NiGeometry *> pRenderedGeometryCache[4];
    BSTPersistentList<NiTPointerAllocator<std::uint32_t>,NiGeometry *> pRendered1stPersonGeometryCache[4];
    NiPointer<NiGeometry> spBoundTestGeometry;
    NiTPointerList<ReferenceVolume *> ReferenceVolumeList;
    std::uint32_t uiLastOcclusionRef;
    bool bLastOcclusionResult;
    NiColorA kSilhouetteColor;
    bool bWaterReflection;
    bool bWaterRefraction;
    bool bCellHasWater;
    bool bUnderWater;
    std::int32_t iCurrentWaterHeight;
    bool bRenderDecals;
    struct BSInstanceRendering *pInstanceRenderer;
    BSBatchRenderer *pBatchRenderer[2];
    std::uint32_t *puicurrentPassA;
    std::int32_t *picurrentBucketA;
    bool *pbcurrentFirstPassA;
    bool *pbcurrentActiveA;
    std::uint32_t uiBatchRendererCount;
    std::uint32_t uiBatchRendererPassCount;
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
