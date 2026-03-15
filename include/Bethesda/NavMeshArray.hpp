#pragma once
#include "Bethesda/BSSimpleArray.hpp"
#include "Bethesda/NavMeshPtr.hpp"

class NavMeshArray
{
  public:
    NavMeshArray();
    ~NavMeshArray();

    BSSimpleArray<NavMeshPtr, 1024> NavMeshes;
};

static_assert(sizeof(NavMeshArray) == 0x10, "NavMeshArray has wrong size");
