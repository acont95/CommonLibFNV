#pragma once
#include "Gamebryo/NiGeometry.hpp"

class NiTriBasedGeom : NiGeometry
{
  public:
    NiTriBasedGeom();
    virtual ~NiTriBasedGeom();
};

static_assert(sizeof(NiTriBasedGeom) == 0xC4, "NiTriBasedGeom has wrong size");
