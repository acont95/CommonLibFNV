#pragma once
#include "Gamebryo/NiRefObject.hpp"

class NiObject : NiRefObject 
{
  public:
    NiObject();
    ~NiObject();
};

static_assert(sizeof(NiObject) == 0x8, "NiObject has wrong size");
