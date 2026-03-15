#pragma once
#include "Bethesda/BSSimpleArray.hpp"
#include "Gamebryo/NiPoint3.hpp"

class NavMeshBounds
{
  public:
    NavMeshBounds();
    ~NavMeshBounds();

    struct NavMeshBoundsTriangle
    {
      unsigned __int16 Vertices[3];
    };

    NiPoint3 BoundingBoxMin;
    NiPoint3 BoundingBoxMax;
    BSSimpleArray<NavMeshBounds::NavMeshBoundsTriangle,1024> Triangles;
    BSSimpleArray<NiPoint3,1024> Vertices;
};

static_assert(sizeof(NavMeshBounds) == 0x38, "NavMeshBounds has wrong size");
