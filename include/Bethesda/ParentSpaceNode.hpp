#pragma once
#include "Bethesda/TESObjectCELL.hpp"
#include "Bethesda/TESWorldSpace.hpp"

class ParentSpaceNode
{
  public:
    ParentSpaceNode();
    ~ParentSpaceNode();

    bool bWorldSpace;
    TESWorldSpace *pWorldSpace;
    TESObjectCELL *pInteriorCell;
};

static_assert(sizeof(ParentSpaceNode) == 0xC, "ParentSpaceNode has wrong size");
