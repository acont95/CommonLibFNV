#pragma once
#include "Bethesda/NavMesh.hpp"
#include "Gamebryo/NiPointer.hpp"

class NavMeshPtr : NiPointer<NavMesh>
{
  public:
    NavMeshPtr();
    ~NavMeshPtr();
};

static_assert(sizeof(NavMeshPtr) == 0x4, "NavMeshPtr has wrong size");
