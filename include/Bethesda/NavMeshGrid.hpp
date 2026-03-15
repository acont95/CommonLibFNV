#pragma once
#include "Bethesda/BSSimpleArray.hpp"
#include "Gamebryo/NiPoint3.hpp"

class NavMeshGrid
{
  public:
    NavMeshGrid();
    ~NavMeshGrid();

    unsigned int iGridSize;
    float fColumnSectionLen;
    float fRowSectionLen;
    NiPoint3 GridBoundsMin;
    NiPoint3 GridBoundsMax;
    BSSimpleArray<unsigned short,1024> *GridData;
};

static_assert(sizeof(NavMeshGrid) == 0x28, "NavMeshGrid has wrong size");
