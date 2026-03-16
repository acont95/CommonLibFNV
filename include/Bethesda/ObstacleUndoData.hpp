#pragma once
#include <cstdint>
#include "Bethesda/ObstacleData.hpp"
#include "Bethesda/BoundsTriangleInfo.hpp"
#include "Bethesda/PortalEdgeSwap.hpp"
#include "Gamebryo/NiTMap.hpp"

class ObstacleUndoData : public NiRefObject
{
  public:
    ObstacleUndoData();
    virtual ~ObstacleUndoData();

    enum OBSTACLE_UNDO_STATE
    {
      OBSTACLE_UNDO_STATE_INVALID = 0x0,
      OBSTACLE_UNDO_STATE_ACTIVE = 0x1,
      OBSTACLE_UNDO_STATE_WANT_TO_UNDO = 0x2,
      OBSTACLE_UNDO_STATE_UNDONE = 0x3,
      OBSTACLE_UNDO_STATE_DELETED = 0x4,
    };

    OBSTACLE_UNDO_STATE eState;
    NiPointer<ObstacleData> spObstacle;
    std::uint32_t iFirstAddedVertexIndex;
    std::uint32_t iAddedVertexCount;
    std::uint32_t iFirstAddedTriangleIndex;
    std::uint32_t iAddedTriangleCount;
    BSSimpleArray<unsigned short,1024> OverlappedTriangles;
    BSSimpleArray<BoundsTriangleInfo,1024> BoundsTriangles;
    NiTMap<unsigned short,NiPointer<ObstacleData> > RemovedTriangleToObstacleMap;
    BSSimpleArray<PortalEdgeSwap,1024> EdgeSwap;
    BSSimpleArray<unsigned short,1024> AddedPOVs;
};

static_assert(sizeof(ObstacleUndoData) == 0x70, "ObstacleUndoData has wrong size");
