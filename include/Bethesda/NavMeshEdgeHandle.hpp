#pragma once
#include <cstdint>
#include "Bethesda/NavMeshTriHandle.hpp"

class NavMeshEdgeHandle : NavMeshTriHandle
{
  public:
    NavMeshEdgeHandle();
    ~NavMeshEdgeHandle();

    std::int32_t iEdgeIndex;
};

static_assert(sizeof(NavMeshEdgeHandle) == 0xC, "NavMeshEdgeHandle has wrong size");
