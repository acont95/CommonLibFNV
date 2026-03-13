#pragma once
#include "Gamebryo/NiObject.hpp"
#include "Gamebryo/NiAVObject.hpp"

class NiCollisionObject : NiObject
{
  public:
    NiCollisionObject();
    ~NiCollisionObject();

    NiAVObject* m_pkSceneObject;
};

static_assert(sizeof(NiCollisionObject) == 0xC, "NiCollisionObject has wrong size");
