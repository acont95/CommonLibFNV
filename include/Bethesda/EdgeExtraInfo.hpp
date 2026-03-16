#pragma once
#include <cstdint>
#include "Bethesda/NavMeshTriangleEdgePortal.hpp"

enum EDGE_EXTRA_INFO_TYPE
{
  EIT_INVALID = 0xFFFFFFFF,
  EIT_PORTAL = 0x0,
  EIT_LEDGE_UP = 0x1,
  EIT_LEDGE_DOWN = 0x2,
  EIT_ENABLE_DISABLE_PORTAL = 0x3,
};

class EdgeExtraInfo
{
  public:
    EdgeExtraInfo();
    ~EdgeExtraInfo();

    EDGE_EXTRA_INFO_TYPE eType;
    NavMeshTriangleEdgePortal Portal;
};

static_assert(sizeof(EdgeExtraInfo) == 0xC, "EdgeExtraInfo has wrong size");
