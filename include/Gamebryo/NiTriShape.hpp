#pragma once
#include "Gamebryo/NiTriBasedGeom.hpp"

class NiTriShape : NiTriBasedGeom
{
  public:
    NiTriShape();
    virtual ~NiTriShape();
};

static_assert(sizeof(NiTriShape) == 0xC4, "NiTextureTransform has wrong size");
