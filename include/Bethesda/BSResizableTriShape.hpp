#pragma once
#include <cstdint>
#include "Gamebryo/NiTriShape.hpp"
#include "Gamebryo/NiBound.hpp"

class BSResizableTriShape : NiTriShape
{
  public:
    BSResizableTriShape();
    virtual ~BSResizableTriShape();

    std::uint32_t uiNumPrimitives;
    NiBound LocalBound;
};

static_assert(sizeof(BSResizableTriShape) == 0xD8, "BSResizableTriShape has wrong size");
