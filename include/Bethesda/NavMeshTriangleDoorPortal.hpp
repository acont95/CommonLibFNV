#pragma once
#include "Bethesda/TESObjectREFR.hpp"

class NavMeshTriangleDoorPortal
{
  public:
    NavMeshTriangleDoorPortal();
    ~NavMeshTriangleDoorPortal();

    TESObjectREFR *pDoorForm;
    unsigned __int16 iOwningTriangleIndex;
};

static_assert(sizeof(NavMeshTriangleDoorPortal) == 0x8, "NavMeshTriangleDoorPortal has wrong size");
