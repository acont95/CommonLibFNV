#pragma once
#include <cstdint>

namespace CommonLib {

  class NavMeshTriangle
  {
    public:

      std::uint16_t Vertices[3];
      std::uint16_t Triangles[3];
      std::uint32_t TriangleFlags;
  };

  static_assert(sizeof(NavMeshTriangle) == 0x10, "NavMeshTriangle has wrong size");
  
} // namespace CommonLib
