#pragma once
#include <cstdint>

class NavMeshTriangle
{
  public:
    NavMeshTriangle();
    ~NavMeshTriangle();

    std::uint16_t Vertices[3];
    std::uint16_t Triangles[3];
    unsigned int TriangleFlags;
};

static_assert(sizeof(NavMeshTriangle) == 0x10, "NavMeshTriangle has wrong size");
