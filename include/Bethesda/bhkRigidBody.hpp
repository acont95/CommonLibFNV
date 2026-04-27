#pragma once
#include "Bethesda/bhkEntity.hpp"
#include "Bethesda/BSSimpleList.hpp"
#include "Gamebryo/NiPointer.hpp"

namespace CommonLib {

  class bhkRigidBody : public bhkEntity
  {
    public:

      BSSimpleList<NiPointer<bhkSerializable>> ActionConstraint;
  };

  static_assert(sizeof(bhkRigidBody) == 0x1C, "bhkRigidBody has wrong size");
  
} // namespace CommonLib
