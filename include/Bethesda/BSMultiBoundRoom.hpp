#pragma once
#include "Bethesda/BSMultiBoundNode.hpp"
#include "Bethesda/BSSimpleArray.hpp"

class BSPortal;
class BSOcclusionPlane;
class BSCompoundFrustum;
class ShadowSceneLight;

class BSMultiBoundRoom : public BSMultiBoundNode 
{
  public:
    BSMultiBoundRoom();
    virtual ~BSMultiBoundRoom();

    NiTPointerList<BSPortal *> kPortalList;
    NiTPointerList<BSOcclusionPlane *> lOccluderList;
    BSCompoundFrustum *pCompoundFrustum;
    NiTPointerList<NiPointer<BSMultiBound> > kJoinedMultiBoundList;
    BSSimpleArray<ShadowSceneLight *,1024> kLights;
};

static_assert(sizeof(BSMultiBoundRoom) == 0xEC, "BSMultiBoundRoom has wrong size");
