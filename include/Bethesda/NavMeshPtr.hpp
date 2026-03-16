#pragma once
#include "Bethesda/NavMesh.hpp"

class NavMeshPtr : public NiPointer<NavMesh>
{
  public:
    NavMeshPtr();
    ~NavMeshPtr();
};

static_assert(sizeof(NavMeshPtr) == 0x4, "NavMeshPtr has wrong size");
