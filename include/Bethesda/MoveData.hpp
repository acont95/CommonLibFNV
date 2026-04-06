#pragma once
#include "Gamebryo/NiPoint3.hpp"

namespace CommonLib {

  class FastModifierCollection;
  class Modifier;

  class MoveData
  {
    public:
      MoveData();
      ~MoveData();

      float fTime;
      NiPoint3 Angle;
      NiPoint3 Displacement;
      unsigned int iMoveDirection;
      float fCurrMoveSpeed;
      bool bVisible;
  };

  static_assert(sizeof(MoveData) == 0x28, "MoveData has wrong size");
  
} // namespace CommonLib
