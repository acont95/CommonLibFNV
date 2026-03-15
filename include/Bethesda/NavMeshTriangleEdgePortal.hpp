#pragma once
#include "Bethesda/NavMeshInfo.hpp"

class NavMeshTriangleEdgePortal
{
  public:
    NavMeshTriangleEdgePortal();
    ~NavMeshTriangleEdgePortal();

    NavMeshInfo *pOtherMesh;
    unsigned __int16 sTriangle;
};

static_assert(sizeof(NavMeshTriangleEdgePortal) == 0x8, "NavMeshTriangleEdgePortal has wrong size");
