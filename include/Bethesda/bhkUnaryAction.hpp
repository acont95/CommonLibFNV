#pragma once
#include "Bethesda/bhkAction.hpp"

namespace CommonLib {

  class bhkUnaryAction : bhkAction
  {
    public:
      bhkUnaryAction();
      virtual ~bhkUnaryAction();
  };

  static_assert(sizeof(bhkUnaryAction) == 0x10, "bhkUnaryAction has wrong size");
  
} // namespace CommonLib
