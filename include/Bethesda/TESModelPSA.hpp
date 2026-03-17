#pragma once
#include "Types.hpp"
#include "Bethesda/TESModel.hpp"

namespace CommonLib {

  class TESModelPSA : TESModel
  {
    public:
      TESModelPSA();
      virtual ~TESModelPSA();
  };

  static_assert(sizeof(TESModelPSA) == 0x18, "TESModelPSA has wrong size");
  
} // namespace CommonLib
