#pragma once
#include "Bethesda/NavMeshInfo.hpp"

class NavMeshTriHandle
{
  public:
    NavMeshTriHandle();
    ~NavMeshTriHandle();

    NavMeshInfo *pNavMeshInfo;
    unsigned __int16 usTriangle;
};

static_assert(sizeof(NavMeshTriHandle) == 0x8, "NavMeshTriHandle has wrong size");
