#pragma once
#include <cstdint>
#include "Bethesda/PathingAvoidNode.hpp"

class NavMeshStaticAvoidNode : public PathingAvoidNode
{
  public:
    NavMeshStaticAvoidNode();
    ~NavMeshStaticAvoidNode();

    std::uint16_t usTriangle;
};

static_assert(sizeof(NavMeshStaticAvoidNode) == 0x28, "NavMeshStaticAvoidNode has wrong size");
