#pragma once
#include "Bethesda/TESForm.hpp"
#include "Bethesda/NavMesh.hpp"
#include "Bethesda/NavMeshBounds.hpp"
#include "Gamebryo/NiPoint3.hpp"

class NavMeshInfo
{
  public:
    NavMeshInfo();
    ~NavMeshInfo();

    unsigned int NavMeshID;
    unsigned int ParentSpaceID;
    unsigned int uiFlags;
    int iCellKey;
    NiPoint3 ApproxLocation;
    TESForm *pParentSpace;
    float fPreferredPercent;
    BSSimpleArray<NavMeshInfo *,1024> AdjacentNavMeshes;
    BSSimpleArray<NavMeshInfo *,1024> PreferredAdjacentNavMeshes;
    BSSimpleArray<TESObjectREFR *,1024> ConnectedDoors;
    NavMesh *pNavMesh;
    NavMeshBounds *pBounds;
};

static_assert(sizeof(NavMeshInfo) == 0x5C, "NavMeshInfo has wrong size");
