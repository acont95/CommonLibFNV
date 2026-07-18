#pragma once
#include "Gamebryo/NiTimeController.hpp"

namespace CommonLib {

  class NiInterpController : public NiTimeController
  {
    public:
      virtual ~NiInterpController();
  };

  static_assert(sizeof(NiInterpController) == 0x34, "NiInterpController has wrong size");
  
} // namespace CommonLib
