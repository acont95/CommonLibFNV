#pragma once
#include "Bethesda/NavMeshEdgeHandle.hpp"

class PortalEdgeSwap
{
  public:
    PortalEdgeSwap();
    ~PortalEdgeSwap();

    NavMeshEdgeHandle hOldEdge;
    NavMeshEdgeHandle hNewEdge;
    bool bFromAddition;
};

static_assert(sizeof(PortalEdgeSwap) == 0x1C, "PortalEdgeSwap has wrong size");
