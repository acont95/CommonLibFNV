#pragma once
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiAVObject.hpp"
#include "Gamebryo/NiTObjectArray.hpp"

class NiNode : NiAVObject
{
  public:
    NiNode();
    virtual ~NiNode();

    NiTObjectArray<NiPointer<NiAVObject>> m_kChildren;
};

static_assert(sizeof(NiNode) == 0xAC, "NiNode has wrong size");
