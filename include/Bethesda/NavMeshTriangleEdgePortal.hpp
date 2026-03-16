#pragma once
#include <cstdint>

class NavMeshInfo;

class NavMeshTriangleEdgePortal
{
  public:
    NavMeshTriangleEdgePortal();
    ~NavMeshTriangleEdgePortal();

    NavMeshInfo *pOtherMesh;
    std::uint16_t sTriangle;
};

static_assert(sizeof(NavMeshTriangleEdgePortal) == 0x8, "NavMeshTriangleEdgePortal has wrong size");
