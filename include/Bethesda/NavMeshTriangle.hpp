#pragma once

class NavMeshTriangle
{
  public:
    NavMeshTriangle();
    ~NavMeshTriangle();

    unsigned __int16 Vertices[3];
    unsigned __int16 Triangles[3];
    unsigned int TriangleFlags;
};

static_assert(sizeof(NavMeshTriangle) == 0x10, "NavMeshTriangle has wrong size");
