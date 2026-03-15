#pragma once
#include "Gamebryo/NiPoint3.hpp"

class NavMeshVertex
{
  public:
    NavMeshVertex();
    ~NavMeshVertex();

    NiPoint3 Location;
};

static_assert(sizeof(NavMeshVertex) == 0xC, "NavMeshVertex has wrong size");
