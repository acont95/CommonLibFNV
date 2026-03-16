#pragma once

class TESWorldSpace;
class TESObjectCELL;

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
