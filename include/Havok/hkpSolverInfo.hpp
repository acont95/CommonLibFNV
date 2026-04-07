#pragma once
#include <cstdint>
#include "Havok/hkVector4.hpp"
#include "Havok/hkBool.hpp"
#include "Havok/hkHalf.hpp"

namespace CommonLib {

  class hkpSolverInfo
  {
    public:
      hkpSolverInfo();
      ~hkpSolverInfo();

      enum DeactivationClass : std::int32_t
      {
        DEACTIVATION_CLASS_INVALID = 0x0,
        DEACTIVATION_CLASS_OFF = 0x1,
        DEACTIVATION_CLASS_LOW = 0x2,
        DEACTIVATION_CLASS_MEDIUM = 0x3,
        DEACTIVATION_CLASS_HIGH = 0x4,
        DEACTIVATION_CLASS_AGGRESSIVE = 0x5,
        DEACTIVATION_CLASSES_END = 0x6,
      };

      class DeactivationInfo
      {
        public:
          float m_linearVelocityThresholdInv;
          float m_angularVelocityThresholdInv;
          float m_slowObjectVelocityMultiplier;
          float m_relativeSleepVelocityThreshold;
          float m_maxDistSqrd[2];
          hkHalf m_maxRotSqrd[2];
      };

      float m_one;
      float m_tau;
      float m_damping;
      float m_frictionTau;
      hkVector4 m_globalAccelerationPerSubStep;
      hkVector4 m_globalAccelerationPerStep;
      hkVector4 m_integrateVelocityFactor;
      hkVector4 m_invIntegrateVelocityFactor;
      float m_dampDivTau;
      float m_tauDivDamp;
      float m_dampDivFrictionTau;
      float m_frictionTauDivDamp;
      float m_contactRestingVelocity;
      hkpSolverInfo::DeactivationInfo m_deactivationInfo[6];
      float m_deltaTime;
      float m_invDeltaTime;
      int m_numSteps;
      int m_numMicroSteps;
      float m_invNumMicroSteps;
      float m_invNumSteps;
      hkBool m_forceCoherentConstraintOrderingInSolver;
      unsigned __int8 m_deactivationNumInactiveFramesSelectFlag[2];
      unsigned __int8 m_deactivationIntegrateCounter;
      float m_maxConstraintViolationSqrd;
  };

  static_assert(sizeof(hkpSolverInfo) == 0x130, "hkpSolverInfo has wrong size");
  
} // namespace CommonLib
