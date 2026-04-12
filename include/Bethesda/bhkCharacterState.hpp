#pragma once
#include "Havok/hkpCharacterState.hpp"

namespace CommonLib {

  class bhkCharacterState : public hkpCharacterState
  {
    public:
      bhkCharacterState();
      virtual ~bhkCharacterState();
  };

  static_assert(sizeof(bhkCharacterState) == 0x8, "bhkCharacterState has wrong size");
  
} // namespace CommonLib
