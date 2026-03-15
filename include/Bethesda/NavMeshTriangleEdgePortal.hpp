#pragma once
#include <cstdint>
#include "Bethesda/NavMeshInfo.hpp"

class NavMeshTriangleEdgePortal
{
  public:
    NavMeshTriangleEdgePortal();
    ~NavMeshTriangleEdgePortal();

    NavMeshInfo *pOtherMesh;
    std::uint16_t sTriangle;
};

static_assert(sizeof(NavMeshTriangleEdgePortal) == 0x8, "NavMeshTriangleEdgePortal has wrong size");
