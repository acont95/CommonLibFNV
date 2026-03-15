#pragma once
#include <cstdint>
#include "Bethesda/BSSimpleArray.hpp"
#include "Bethesda/ObstacleData.hpp"
#include "Gamebryo/NiRefObject.hpp"

class ReferenceObstacleArray : NiRefObject
{
  public:
    ReferenceObstacleArray();
    virtual ~ReferenceObstacleArray();

    std::uint32_t iFormID;
    BSSimpleArray<NiPointer<ObstacleData>, 1024> Obstacles;
};

static_assert(sizeof(ReferenceObstacleArray) == 0x1C, "ReferenceObstacleArray has wrong size");
