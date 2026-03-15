#pragma once
#include "Gamebryo/NiTriShape.hpp"
#include "Gamebryo/NiBound.hpp"

class BSResizableTriShape : NiTriShape
{
  public:
    BSResizableTriShape();
    virtual ~BSResizableTriShape();

    unsigned int uiNumPrimitives;
    NiBound LocalBound;
};

static_assert(sizeof(BSResizableTriShape) == 0xD8, "BSResizableTriShape has wrong size");
