#pragma once
#include "Gamebryo/NiGeometry.hpp"

class NiLines : public NiGeometry
{
  public:
    NiLines();
    ~NiLines();
};

static_assert(sizeof(NiLines) == 0xC4, "NiLines has wrong size");
