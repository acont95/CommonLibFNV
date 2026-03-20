#pragma once
#include "Bethesda/bhkUnaryAction.hpp"

namespace CommonLib {

  class bhkMouseSpringAction : bhkUnaryAction
  {
    public:
      bhkMouseSpringAction();
      virtual ~bhkMouseSpringAction();
  };

  static_assert(sizeof(bhkMouseSpringAction) == 0x10, "bhkMouseSpringAction has wrong size");
  
} // namespace CommonLib
