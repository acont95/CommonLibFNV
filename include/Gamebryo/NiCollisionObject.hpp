#pragma once
#include "Gamebryo/NiObject.hpp"

class NiAVObject;

class NiCollisionObject : public NiObject
{
  public:
    NiCollisionObject();
    ~NiCollisionObject();

    NiAVObject* m_pkSceneObject;
};

static_assert(sizeof(NiCollisionObject) == 0xC, "NiCollisionObject has wrong size");
