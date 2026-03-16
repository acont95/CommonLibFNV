#pragma once
#include <cstdint>
#include "Bethesda/ShadowSceneLight.hpp"
#include "Bethesda/BSCubeMapCamera.hpp"
#include "Bethesda/BSFogProperty.hpp"
#include "Bethesda/BSCompoundFrustum.hpp"
#include "Gamebryo/NiNode.hpp"

class ShadowSceneNode : public NiNode
{
  public:
    ShadowSceneNode();
    virtual ~ShadowSceneNode();

    enum eChildNodes
    {
      SSN_CHILDNODE_SKY = 0x0,
      SSN_CHILDNODE_WEATHER = 0x1,
      SSN_CHILDNODE_LOD = 0x2,
      SSN_CHILDNODE_OBJECTLOD = 0x3,
      SSN_CHILDNODE_NAVMESH = 0x4,
      SSN_CHILDNODE_MPS = 0x5,
      SSN_CHILDNODE_GRASS = 0x6,
    };

    bool bFrustumAddedToVis;
    float fStoredFarClip;
    NiTPointerList<NiPointer<ShadowSceneLight> > lLightList;
    NiTPointerList<NiPointer<ShadowSceneLight> > lShadowLightList;
    void *kShadowLightListIterator;
    void *kShadowLightActiveFence;
    void *kShadowLightFadingInFence;
    NiPointer<ShadowSceneLight> kShadowLightActiveFenceObject;
    NiPointer<ShadowSceneLight> kShadowLightFadingInFenceObject;
    ShadowSceneLight *pSunLight;
    NiTPointerList<NiPointer<ShadowSceneLight> > lLightQueueAdd;
    NiTPointerList<NiPointer<ShadowSceneLight> > lLightQueueRemove;
    NiTPointerList<NiPointer<ShadowSceneLight> > lLightQueueUpdate;
    NiTPointerList<NiPointer<NiAVObject> > lObjectQueueUpdate;
    NiTPointerList<NiPointer<NiAVObject> > lObjectQueueUpdateActiveOnly;
    std::uint8_t cSceneGraphIndex;
    NiPointer<BSRenderedTexture> pWindowReflectionEnvMap;
    NiPointer<BSCubeMapCamera> spCubeMapCamera;
    std::int32_t iCurrentCubeMapFace;
    bool bDisableLightUpdate;
    bool bWireframe;
    NiPointer<BSFogProperty> spFog;
    BSCompoundFrustum kCompoundFrustum;
    bool bVisibleUnboundSpace;
    BSPortalGraph *pBSPortalGraph;
    NiPoint3 kLightingOffset;
    NiPoint3 kEyePosition;
    bool bAllowLightRemoveQueues;
};

static_assert(sizeof(ShadowSceneNode) == 0x200, "ShadowSceneNode has wrong size");
