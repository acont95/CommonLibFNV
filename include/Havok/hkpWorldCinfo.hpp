#pragma once
#include <cstdint>
#include "Havok/hkReferencedObject.hpp"
#include "Havok/hkBool.hpp"
#include "Havok/hkVector4.hpp"
#include "Havok/hkEnum.hpp"
#include "Havok/hkAabb.hpp"
#include "Havok/hkRefPtr.hpp"

namespace CommonLib {

  class hkpCollisionFilter;
  class hkpConvexListFilter;
  class hkWorldMemoryAvailableWatchDog;

  class hkpWorldCinfo : public hkReferencedObject
  {
    public:
      hkpWorldCinfo();
      virtual ~hkpWorldCinfo();

      enum SolverType : std::int32_t
      {
        SOLVER_TYPE_INVALID = 0x0,
        SOLVER_TYPE_2ITERS_SOFT = 0x1,
        SOLVER_TYPE_2ITERS_MEDIUM = 0x2,
        SOLVER_TYPE_2ITERS_HARD = 0x3,
        SOLVER_TYPE_4ITERS_SOFT = 0x4,
        SOLVER_TYPE_4ITERS_MEDIUM = 0x5,
        SOLVER_TYPE_4ITERS_HARD = 0x6,
        SOLVER_TYPE_8ITERS_SOFT = 0x7,
        SOLVER_TYPE_8ITERS_MEDIUM = 0x8,
        SOLVER_TYPE_8ITERS_HARD = 0x9,
        SOLVER_TYPE_MAX_ID = 0xA,
      };

      enum SimulationType : std::int32_t
      {
        SIMULATION_TYPE_INVALID = 0x0,
        SIMULATION_TYPE_DISCRETE = 0x1,
        SIMULATION_TYPE_CONTINUOUS = 0x2,
        SIMULATION_TYPE_MULTITHREADED = 0x3,
      };

      enum ContactPointGeneration : std::int32_t
      {
        CONTACT_POINT_ACCEPT_ALWAYS = 0x0,
        CONTACT_POINT_REJECT_DUBIOUS = 0x1,
        CONTACT_POINT_REJECT_MANY = 0x2,
      };

      enum BroadPhaseBorderBehaviour : std::int32_t
      {
        BROADPHASE_BORDER_ASSERT = 0x0,
        BROADPHASE_BORDER_FIX_ENTITY = 0x1,
        BROADPHASE_BORDER_REMOVE_ENTITY = 0x2,
        BROADPHASE_BORDER_DO_NOTHING = 0x3,
      };

      enum TreeUpdateType : std::int32_t
      {
        REBUILD_ACTIVE = 0x0,
        REBUILD_ALL = 0x1,
      };

      hkVector4 m_gravity;
      int m_broadPhaseQuerySize;
      float m_contactRestingVelocity;
      hkEnum<BroadPhaseBorderBehaviour, signed char> m_broadPhaseBorderBehaviour;
      hkBool m_mtPostponeAndSortBroadPhaseBorderCallbacks;
      hkAabb m_broadPhaseWorldAabb;
      hkBool m_useKdTree;
      hkBool m_useMultipleTree;
      hkEnum<TreeUpdateType,signed char> m_treeUpdateType;
      hkBool m_autoUpdateKdTree;
      float m_collisionTolerance;
      hkRefPtr<hkpCollisionFilter> m_collisionFilter;
      hkRefPtr<hkpConvexListFilter> m_convexListFilter;
      float m_expectedMaxLinearVelocity;
      int m_sizeOfToiEventQueue;
      float m_expectedMinPsiDeltaTime;
      hkRefPtr<hkWorldMemoryAvailableWatchDog> m_memoryWatchDog;
      int m_broadPhaseNumMarkers;
      hkEnum<ContactPointGeneration,signed char> m_contactPointGeneration;
      hkBool m_allowToSkipConfirmedCallbacks;
      float m_solverTau;
      float m_solverDamp;
      int m_solverIterations;
      int m_solverMicrosteps;
      float m_maxConstraintViolation;
      hkBool m_forceCoherentConstraintOrderingInSolver;
      float m_snapCollisionToConvexEdgeThreshold;
      float m_snapCollisionToConcaveEdgeThreshold;
      hkBool m_enableToiWeldRejection;
      hkBool m_enableDeprecatedWelding;
      float m_iterativeLinearCastEarlyOutDistance;
      int m_iterativeLinearCastMaxIterations;
      std::uint8_t m_deactivationNumInactiveFramesSelectFlag0;
      std::uint8_t m_deactivationNumInactiveFramesSelectFlag1;
      std::uint8_t m_deactivationIntegrateCounter;
      hkBool m_shouldActivateOnRigidBodyTransformChange;
      float m_deactivationReferenceDistance;
      float m_toiCollisionResponseRotateNormal;
      int m_maxSectorsPerCollideTask;
      hkBool m_processToisMultithreaded;
      int m_maxEntriesPerToiCollideTask;
      int m_maxNumToiCollisionPairsSinglethreaded;
      float m_numToisTillAllowedPenetrationSimplifiedToi;
      float m_numToisTillAllowedPenetrationToi;
      float m_numToisTillAllowedPenetrationToiHigher;
      float m_numToisTillAllowedPenetrationToiForced;
      hkBool m_enableDeactivation;
      hkEnum<SimulationType, signed char> m_simulationType;
      hkBool m_enableSimulationIslands;
      unsigned int m_minDesiredIslandSize;
      hkBool m_processActionsInSingleThread;
      hkBool m_allowIntegrationOfIslandsWithoutConstraintsInASeparateJob;
      float m_frameMarkerPsiSnap;
      hkBool m_fireCollisionCallbacks;
  };

  static_assert(sizeof(hkpWorldCinfo) == 0xF0, "hkpWorldCinfo has wrong size");
  
} // namespace CommonLib
