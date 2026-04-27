#pragma once
#include <cstdint>
#include "Bethesda/BSSimpleArray.hpp"
#include "Gamebryo/NiPoint3.hpp"

namespace CommonLib {

  class NavMeshBounds
  {
    public:

      struct NavMeshBoundsTriangle
      {
        std::uint16_t Vertices[3];
      };

      NiPoint3 BoundingBoxMin;
      NiPoint3 BoundingBoxMax;
      BSSimpleArray<NavMeshBounds::NavMeshBoundsTriangle,1024> Triangles;
      BSSimpleArray<NiPoint3,1024> Vertices;
  };

  static_assert(sizeof(NavMeshBounds) == 0x38, "NavMeshBounds has wrong size");
  
} // namespace CommonLib
