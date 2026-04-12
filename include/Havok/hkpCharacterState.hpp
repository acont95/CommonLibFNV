#pragma once
#include "Havok/hkReferencedObject.hpp"

namespace CommonLib {

  class hkpCharacterState : public hkReferencedObject
  {
    public:
      hkpCharacterState();
      virtual ~hkpCharacterState();
  };

  static_assert(sizeof(hkpCharacterState) == 0x8, "hkpCharacterState has wrong size");
  
} // namespace CommonLib
