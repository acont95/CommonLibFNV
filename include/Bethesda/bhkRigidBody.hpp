#pragma once
#include "Bethesda/bhkEntity.hpp"
#include "Bethesda/BSSimpleList.hpp"
#include "Gamebryo/NiPointer.hpp"

class bhkRigidBody : public bhkEntity
{
  public:
    bhkRigidBody();
    ~bhkRigidBody();

    BSSimpleList<NiPointer<bhkSerializable>> ActionConstraint;
};

static_assert(sizeof(bhkRigidBody) == 0x1C, "bhkRigidBody has wrong size");
