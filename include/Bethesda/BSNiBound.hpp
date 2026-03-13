#pragma once
#include "Gamebryo/NiBound.hpp"

class BSNiBound : NiBound
{
  public:
    BSNiBound();
    ~BSNiBound();
};

static_assert(sizeof(BSNiBound) == 0x10, "BSNiBound has wrong size");
