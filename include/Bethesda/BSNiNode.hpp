#pragma once
#include "Gamebryo/NiNode.hpp"

class BSNiNode : NiNode
{
  public:
    BSNiNode();
    virtual ~BSNiNode();
};

static_assert(sizeof(BSNiNode) == 0xAC, "BSNiNode has wrong size");
