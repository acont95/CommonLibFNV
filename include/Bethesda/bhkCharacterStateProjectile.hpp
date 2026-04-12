#pragma once
#include "Bethesda/bhkCharacterState.hpp"

namespace CommonLib {

  class bhkCharacterStateProjectile : public bhkCharacterState
  {
    public:
      bhkCharacterStateProjectile();
      virtual ~bhkCharacterStateProjectile();
  };

  static_assert(sizeof(bhkCharacterStateProjectile) == 0x8, "bhkCharacterStateProjectile has wrong size");
  
} // namespace CommonLib
