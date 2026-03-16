#pragma once
#include <cstdint>
#include <Types.hpp>
#include "Bethesda/BSRenderedTexture.hpp"
#include "Bethesda/BSSimpleArray.hpp"
#include "Bethesda/BSShaderAccumulator.hpp"
#include "Gamebryo/NiLight.hpp"
#include "Gamebryo/NiFrustumPlanes.hpp"
#include "Gamebryo/NiTriBasedGeom.hpp"

class BSMultiBoundNode;
class BSPortal;
class BSPortalGraph;

class ShadowSceneLight : public NiRefObject
{
  public:
    ShadowSceneLight();
    virtual ~ShadowSceneLight();

    enum eFrustumCull : std::int32_t
    {
      SSL_NONE = 0x0,
      SSL_POSX = 0x1,
      SSL_NEGX = 0x2,
      SSL_POSY = 0x4,
      SSL_NEGY = 0x8,
      SSL_POSZ = 0x10,
      SSL_NEGZ = 0x20,
      SSL_ALL = 0xFF,
    };

    std::int32_t iEnabledPasses;
    float fLuminance;
    D3DXMATRIX kViewProjection;
    D3DXMATRIX kShadowView;
    D3DXMATRIX kShadowProj;
    float fLODDimmer;
    float fShadowLODDimmer;
    float fShadowLODDimmerTarget;
    float fShadowLODDimmerElapsed;
    NiTPointerList<NiPointer<NiTriBasedGeom> > lGeomList;
    bool bCastShadow;
    bool bCubeShadowMap;
    NiPointer<NiTexture> spSpecularAttenuationTexture;
    bool bPointLight;
    bool bAmbientLight;
    NiPointer<NiLight> spLight;
    bool bDynamicLight;
    NiPoint3 bPointPosition;
    NiPointer<BSRenderedTexture> spDynamicShadowMap;
    std::uint16_t usFrustumCull;
    NiPointer<NiAVObject> spFrustumVis;
    bool bShadowSpotlight;
    float fSpotlightFOV;
    float fSpotlightFalloff;
    bool bShowDebugTexture;
    NiPointer<NiAVObject> spShadowScene;
    NiTPointerList<NiPointer<NiAVObject> > lRootList;
    void *kGeomListFence;
    NiPointer<NiTriBasedGeom> kGeomListFenceObject;
    NiPointer<NiCamera> spShadowCamera;
    NiFrustumPlanes kShadowCameraPlanes;
    float pfClipSpacePlanes[24];
    bool bClipSpacePlanesReady;
    NiPointer<BSShaderAccumulator> spShadowAccumulator;
    BSSimpleArray<BSMultiBoundNode *,1024> kMultiboundRooms;
    BSSimpleArray<BSPortal *,1024> kPortals;
    BSSimpleArray<NiNode *,1024> kProcessedNodes;
    BSPortalGraph *pPortalGraph;
};

// static_assert(sizeof(ShadowSceneLight) == 0x250, "ShadowSceneLight has wrong size");
