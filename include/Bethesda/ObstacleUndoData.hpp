#pragma once
#include <cstdint>
#include "Bethesda/BSSimpleArray.hpp"
#include "Bethesda/ObstacleData.hpp"
#include "Bethesda/BoundsTriangleInfo.hpp"
#include "Bethesda/PortalEdgeSwap.hpp"
#include "Gamebryo/NiRefObject.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiTMap.hpp"

class ObstacleUndoData : public NiRefObject
{
  public:
    ObstacleUndoData();
    virtual ~ObstacleUndoData();

    enum OBSTACLE_UNDO_STATE : std::int32_t
    {
      OBSTACLE_UNDO_STATE_INVALID = 0x0,
      OBSTACLE_UNDO_STATE_ACTIVE = 0x1,
      OBSTACLE_UNDO_STATE_WANT_TO_UNDO = 0x2,
      OBSTACLE_UNDO_STATE_UNDONE = 0x3,
      OBSTACLE_UNDO_STATE_DELETED = 0x4,
    };

    OBSTACLE_UNDO_STATE eState;
    NiPointer<ObstacleData> spObstacle;
    unsigned int iFirstAddedVertexIndex;
    unsigned int iAddedVertexCount;
    unsigned int iFirstAddedTriangleIndex;
    unsigned int iAddedTriangleCount;
    BSSimpleArray<unsigned short,1024> OverlappedTriangles;
    BSSimpleArray<BoundsTriangleInfo,1024> BoundsTriangles;
    NiTMap<unsigned short,NiPointer<ObstacleData> > RemovedTriangleToObstacleMap;
    BSSimpleArray<PortalEdgeSwap,1024> EdgeSwap;
    BSSimpleArray<unsigned short,1024> AddedPOVs;
};

static_assert(sizeof(ObstacleUndoData) == 0x70, "ObstacleUndoData has wrong size");
