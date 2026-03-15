#pragma once 
#include "Gamebryo/NiObject.hpp"

class BSTextureSet : NiObject
{
  public:
    BSTextureSet();
    ~BSTextureSet();
};

static_assert(sizeof(BSTextureSet) == 0x8, "BSTextureSet has wrong size");
