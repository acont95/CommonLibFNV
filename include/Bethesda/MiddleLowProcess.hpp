#pragma once
#include <cstdint>
#include "Types.hpp"
#include "Bethesda/LowProcess.hpp"

namespace CommonLib {


  class MiddleLowProcess : public LowProcess
  {
    public:
      virtual bool ProcessCombatOneHour(Actor*, float);
      
      int iHourPackageEvaluated;
      ModifierList pTemporaryModifiers;
  };

  static_assert(sizeof(MiddleLowProcess) == 0xC8, "MiddleLowProcess has wrong size");
  
} // namespace CommonLib
