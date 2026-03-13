#pragma once
#include "Gamebryo/NiObject.hpp"
#include "Bethesda/hkReferencedObject.hpp"

class bhkRefObject : NiObject
{
  public:
    bhkRefObject();
    ~bhkRefObject();

    hkReferencedObject *phkObject;
};

static_assert(sizeof(bhkRefObject) == 0xC, "bhkRefObject has wrong size");
