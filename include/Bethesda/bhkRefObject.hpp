#pragma once
#include "Gamebryo/NiObject.hpp"

class hkReferencedObject;

class bhkRefObject : public NiObject
{
  public:
    bhkRefObject();
    ~bhkRefObject();

    hkReferencedObject *phkObject;
};

static_assert(sizeof(bhkRefObject) == 0xC, "bhkRefObject has wrong size");
