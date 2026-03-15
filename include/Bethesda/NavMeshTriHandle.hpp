#pragma once
#include <cstdint>
#include "Bethesda/NavMeshInfo.hpp"

class NavMeshTriHandle
{
  public:
    NavMeshTriHandle();
    ~NavMeshTriHandle();

    NavMeshInfo *pNavMeshInfo;
    std::uint16_t usTriangle;
};

static_assert(sizeof(NavMeshTriHandle) == 0x8, "NavMeshTriHandle has wrong size");
