#pragma once
#include <cstdint>
#include "Bethesda/TESObjectREFR.hpp"

class NavMeshTriangleDoorPortal
{
  public:
    NavMeshTriangleDoorPortal();
    ~NavMeshTriangleDoorPortal();

    TESObjectREFR *pDoorForm;
    std::uint16_t iOwningTriangleIndex;
};

static_assert(sizeof(NavMeshTriangleDoorPortal) == 0x8, "NavMeshTriangleDoorPortal has wrong size");
