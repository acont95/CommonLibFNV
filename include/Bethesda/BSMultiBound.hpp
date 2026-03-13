#pragma once
#include "Bethesda/BSMultiBoundShape.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiObject.hpp"

class BSMultiBound : NiObject
{
  public:
    BSMultiBound();
    ~BSMultiBound();

    unsigned int uiBoundFrameCount;
    NiPointer<BSMultiBoundShape> spShape;
};

static_assert(sizeof(BSMultiBound) == 0x10, "BSMultiBound has wrong size");
