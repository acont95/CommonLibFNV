#pragma once
#include "Bethesda/BSCompoundFrustum.hpp"
#include "Bethesda/BSSimpleArray.hpp"
#include "Bethesda/ShadowSceneLight.hpp"
#include "Bethesda/BSPortal.hpp"
#include "Gamebryo/NiNode.hpp"

class BSPortalSharedNode : NiNode
{
  public:
    BSPortalSharedNode();
    virtual ~BSPortalSharedNode();

    BSCompoundFrustum *pCompoundFrustum;
    BSSimpleArray<ShadowSceneLight*, 1024> kLights;
    BSPortal *pPortal;
};

static_assert(sizeof(BSPortalSharedNode) == 0xC4, "BSPortalSharedNode has wrong size");
