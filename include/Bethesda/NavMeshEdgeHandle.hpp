#pragma once
#include "Bethesda/NavMeshTriHandle.hpp"

class NavMeshEdgeHandle : NavMeshTriHandle
{
  public:
    NavMeshEdgeHandle();
    ~NavMeshEdgeHandle();

    int iEdgeIndex;
};

static_assert(sizeof(NavMeshEdgeHandle) == 0xC, "NavMeshEdgeHandle has wrong size");
