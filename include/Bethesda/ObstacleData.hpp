#pragma once
#include "Bethesda/BSSimpleArray.hpp"
#include "Bethesda/NavMeshInfo.hpp"
#include "Bethesda/ReferenceObstacleArray.hpp"
#include "Gamebryo/NiRefObject.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiPoint3.hpp"
#include "Gamebryo/NiMatrix3.hpp"

class ObstacleData : NiRefObject
{
  public:
    ObstacleData();
    virtual ~ObstacleData();

    ReferenceObstacleArray *spParentArray;
    NiPointer<bhkRigidBody> pRigidBody;
    NiPoint3 Center;
    NiMatrix3 Orientation;
    NiPoint3 BoxMin;
    NiPoint3 BoxMax;
    NiPoint3 aabbMin;
    NiPoint3 aabbMax;
    unsigned int iLastUpdateTime;
    bool bActive;
    BSSimpleArray<NavMeshInfo *,1024> Navmeshes;
    NiPointer<NiTriShape> sp3DNode;
};

static_assert(sizeof(ObstacleData) == 0x8C, "ObstacleData has wrong size");
