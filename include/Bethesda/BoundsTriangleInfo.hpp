#pragma once

class BoundsTriangleInfo
{
  public:
    BoundsTriangleInfo();
    ~BoundsTriangleInfo();

    unsigned __int16 usTriangleIndex;
    bool bPortals[3];
    unsigned __int16 Triangles[3];
};

static_assert(sizeof(BoundsTriangleInfo) == 0xC, "BoundsTriangleInfo has wrong size");