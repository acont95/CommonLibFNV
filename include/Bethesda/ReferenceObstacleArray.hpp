#pragma once
#include <cstdint>
#include "Bethesda/ObstacleData.hpp"

namespace CommonLib {

  class ReferenceObstacleArray : public NiRefObject
  {
    public:
      ReferenceObstacleArray();
      virtual ~ReferenceObstacleArray();

      std::uint32_t iFormID;
      BSSimpleArray<NiPointer<ObstacleData>, 1024> Obstacles;
  };

  static_assert(sizeof(ReferenceObstacleArray) == 0x1C, "ReferenceObstacleArray has wrong size");
  
} // namespace CommonLib
