#pragma once
#include "Bethesda/TESForm.hpp"
#include "Bethesda/TESChildCell.hpp"
#include "Bethesda/NavMeshVertex.hpp"
#include "Bethesda/NavMeshTriangle.hpp"
#include "Bethesda/EdgeExtraInfo.hpp"
#include "Bethesda/NavMeshTriangleDoorPortal.hpp"
#include "Bethesda/NavMeshClosedDoorInfo.hpp"
#include "Bethesda/NavMeshGrid.hpp"
#include "Bethesda/ObstacleUndoData.hpp"
#include "Bethesda/NavMeshStaticAvoidNode.hpp"

struct NavMeshPOVEdge
{
  unsigned __int16 EdgeIndex;
};

struct NavMeshPOVData
{
  NavMeshPOVEdge Edge1;
  NavMeshPOVEdge Edge2;
};

class NavMesh : TESForm, TESChildCell, NiRefObject
{
  public:
    NavMesh();
    virtual ~NavMesh();

    TESObjectCELL *pParentCell;
    BSSimpleArray<NavMeshVertex,1024> Vertices;
    BSSimpleArray<NavMeshTriangle,1024> Triangles;
    BSSimpleArray<EdgeExtraInfo,1024> ExtraEdgeInfo;
    BSSimpleArray<NavMeshTriangleDoorPortal,1024> DoorPortals;
    BSSimpleArray<NavMeshClosedDoorInfo,1024> ClosedDoors;
    BSSimpleArray<unsigned short,1024> CoverArray;
    NiTMap<unsigned short,NavMeshPOVData> POVs;
    BSSimpleArray<unsigned short,1024> ClosestPOVs;
    NavMeshGrid MeshGrid;
    BSSimpleArray<NiPointer<ObstacleUndoData>,1024> Obstacles;
    NiTMap<unsigned short,NiPointer<ObstacleData> > *pTriangleToObstacleMap;
    BSSimpleArray<unsigned short,1024> ObstaclePOVs;
    BSSimpleArray<NavMeshStaticAvoidNode,1024> StaticAvoidNodes;
    NavMeshInfo *pNavMeshInfo;
};

static_assert(sizeof(NavMesh) == 0x108, "NavMesh has wrong size");
