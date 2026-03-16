#pragma once
#include "Bethesda/BSSimpleArray.hpp"
#include "Gamebryo/NiNode.hpp"

class BSCompoundFrustum;
class BSPortal;
class ShadowSceneLight;

class BSPortalSharedNode : public NiNode
{
  public:
    BSPortalSharedNode();
    virtual ~BSPortalSharedNode();

    BSCompoundFrustum *pCompoundFrustum;
    BSSimpleArray<ShadowSceneLight*, 1024> kLights;
    BSPortal *pPortal;
};

static_assert(sizeof(BSPortalSharedNode) == 0xC4, "BSPortalSharedNode has wrong size");
