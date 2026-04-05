#pragma once
#include "Bethesda/bhkSimpleShapePhantom.hpp"

namespace CommonLib {

  class bhkCharacterController;

  class bhkCollisionBox : public bhkSimpleShapePhantom
  {
    public:
      bhkCollisionBox();
      virtual ~bhkCollisionBox();
      
      bhkCharacterController *pCharController;
      bool bDisabled;
  };

  static_assert(sizeof(bhkCollisionBox) == 0x20, "bhkCollisionBox has wrong size");
  
} // namespace CommonLib
