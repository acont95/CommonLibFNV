#pragma once
#include <cstdint>
#include "Havok/hkStepInfo.hpp"
#include "Havok/hkpSolverInfo.hpp"

namespace CommonLib {

  class hkpWorldDynamicsStepInfo
  {
    public:
      hkpWorldDynamicsStepInfo();
      ~hkpWorldDynamicsStepInfo();

      hkStepInfo m_stepInfo;
      hkpSolverInfo m_solverInfo;
  };

  static_assert(sizeof(hkpWorldDynamicsStepInfo) == 0x140, "hkpWorldDynamicsStepInfo has wrong size");
  
} // namespace CommonLib
