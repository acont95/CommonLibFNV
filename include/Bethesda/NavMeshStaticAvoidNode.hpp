#pragma once
#include "Bethesda/PathingAvoidNode.hpp"

class NavMeshStaticAvoidNode : PathingAvoidNode
{
  public:
    NavMeshStaticAvoidNode();
    ~NavMeshStaticAvoidNode();

    unsigned __int16 usTriangle;
};

static_assert(sizeof(NavMeshStaticAvoidNode) == 0x28, "NavMeshStaticAvoidNode has wrong size");
