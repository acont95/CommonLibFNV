#pragma once
#include <cstdint>
#include "Gamebryo/NiPoint3.hpp"

class PathingAvoidNode
{
  public:
    PathingAvoidNode();
    ~PathingAvoidNode();

    enum AVOID_NODE_TYPE
    {
      AVOID_NODE_SPHERE = 0x0,
      AVOID_NODE_CYLINDER = 0x1,
      AVOID_NODE_SPHERE_ACTOR = 0x2,
    };

    NiPoint3 Point1;
    NiPoint3 Point2;
    float fRadius;
    float fCost;
    PathingAvoidNode::AVOID_NODE_TYPE eType;
};

static_assert(sizeof(PathingAvoidNode) == 0x24, "PathingAvoidNode has wrong size");
