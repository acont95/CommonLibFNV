#pragma once
#include "Bethesda/BSMultiBoundRoom.hpp"
#include "Bethesda/BSPortalSharedNode.hpp"
#include "Bethesda/BSOcclusionPlane.hpp"
#include "Gamebryo/NiPointer.hpp"

class BSPortal : BSOcclusionPlane
{
  public:
    BSPortal();
    virtual ~BSPortal();

    BSMultiBoundRoom *pMultiBoundRoom[2];
    NiPointer<BSPortalSharedNode> spSharedGeometry;
};

static_assert(sizeof(BSPortal) == 0x108, "BSPortal has wrong size");
