#pragma once
#include <cstdint>

class BoundsTriangleInfo
{
  public:
    BoundsTriangleInfo();
    ~BoundsTriangleInfo();

    std::uint16_t usTriangleIndex;
    bool bPortals[3];
    std::uint16_t Triangles[3];
};

static_assert(sizeof(BoundsTriangleInfo) == 0xC, "BoundsTriangleInfo has wrong size");