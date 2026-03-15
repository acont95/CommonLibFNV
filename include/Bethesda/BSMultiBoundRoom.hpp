#pragma once
#include "Bethesda/BSMultiBoundNode.hpp"
#include "Bethesda/BSPortal.hpp"
#include "Bethesda/BSOcclusionPlane.hpp"
#include "Bethesda/BSCompoundFrustum.hpp"
#include "Bethesda/BSMultiBound.hpp"
#include "Bethesda/BSSimpleArray.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiTPointerList.hpp"

class BSMultiBoundRoom : BSMultiBoundNode 
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
