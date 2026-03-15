#pragma once
#include "Gamebryo/NiObject.hpp"
#include "Gamebryo/NiTPrimitiveArray.hpp"
#include "Gamebryo/NiAVObject.hpp"

class BSNodeReferences : NiObject
{
  public:
    BSNodeReferences();
    virtual ~BSNodeReferences();

    NiTPrimitiveArray<NiAVObject*> RefNodeA;
};

static_assert(sizeof(BSNodeReferences) == 0x18, "BSNodeReferences has wrong size");