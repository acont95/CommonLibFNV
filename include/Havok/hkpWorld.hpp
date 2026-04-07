#pragma once
#include <cstdint>
#include "Havok/hkReferencedObject.hpp"
#include "Havok/hkArray.hpp"
#include "Havok/hkContainerHeapAllocator.hpp"
#include "Havok/hkRefPtr.hpp"
#include "Havok/hkBool.hpp"
#include "Havok/hkVector4.hpp"
#include "Havok/hkEnum.hpp"
#include "Havok/hkpWorldCinfo.hpp"
#include "Havok/hkMultiThreadCheck.hpp"
#include "Havok/hkpWorldDynamicsStepInfo.hpp"

namespace CommonLib {

  class hkpSimulation;
  class hkpSimulationIsland;
  class hkpRigidBody;
  class hkpWorldMaintenanceMgr;
  class hkWorldMemoryAvailableWatchDog;
  class hkpBroadPhase;
  class hkpTreeWorldManager;
  class hkpTypedBroadPhaseDispatcher;
  class hkpPhantomBroadPhaseListener;
  class hkpEntityEntityBroadPhaseListener;
  class hkpBroadPhaseBorderListener;
  class hkpProcessCollisionInput;
  class hkpCollisionFilter;
  class hkpCollisionDispatcher;
  class hkpConvexListFilter;
  class hkpMtThreadStructure;
  class hkpWorldOperationQueue;
  class hkpDebugInfoOnPendingOperationQueues;
  class hkCriticalSection;
  class hkpPhantom;
  class hkpActionListener;
  class hkpPhantomListener;
  class hkpEntityListener;
  class hkpConstraintListener;
  class hkpWorldDeletionListener;
  class hkpIslandActivationListener;
  class hkpWorldPostSimulationListener;
  class hkpWorldPostIntegrateListener;
  class hkpWorldPostCollideListener;
  class hkpIslandPostIntegrateListener;
  class hkpContactListener;
  class hkpIslandPostCollideListener;
  class hkpContactImpulseLimitBreachedListener;
  class hkpViolatedConstraintArray;
  class hkpBroadPhaseBorder;
  class hkpCollisionCallbackUtil;

  class hkpWorld : public hkReferencedObject
  {
    public:
      hkpWorld();
      virtual ~hkpWorld();

      hkpSimulation *m_simulation;
      hkVector4 m_gravity;
      hkpSimulationIsland *m_fixedIsland;
      hkpRigidBody *m_fixedRigidBody;
      hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> m_activeSimulationIslands;
      hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> m_inactiveSimulationIslands;
      hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> m_dirtySimulationIslands;
      hkpWorldMaintenanceMgr *m_maintenanceMgr;
      hkRefPtr<hkWorldMemoryAvailableWatchDog> m_memoryWatchDog;
      hkBool m_assertOnRunningOutOfSolverMemory;
      hkpBroadPhase *m_broadPhase;
      hkpTreeWorldManager *m_kdTreeManager;
      hkBool m_autoUpdateTree;
      hkpTypedBroadPhaseDispatcher *m_broadPhaseDispatcher;
      hkpPhantomBroadPhaseListener *m_phantomBroadPhaseListener;
      hkpEntityEntityBroadPhaseListener *m_entityEntityBroadPhaseListener;
      hkpBroadPhaseBorderListener *m_broadPhaseBorderListener;
      hkpMtThreadStructure *m_multithreadedSimulationJobData;
      hkpProcessCollisionInput *m_collisionInput;
      hkpCollisionFilter *m_collisionFilter;
      hkpCollisionDispatcher *m_collisionDispatcher;
      hkpConvexListFilter *m_convexListFilter;
      hkpWorldOperationQueue *m_pendingOperations;
      int m_pendingOperationsCount;
      int m_pendingBodyOperationsCount;
      int m_criticalOperationsLockCount;
      int m_criticalOperationsLockCountForPhantoms;
      hkBool m_blockExecutingPendingOperations;
      hkBool m_criticalOperationsAllowed;
      hkpDebugInfoOnPendingOperationQueues *m_pendingOperationQueues;
      int m_pendingOperationQueueCount;
      hkMultiThreadCheck m_multiThreadCheck;
      hkBool m_processActionsInSingleThread;
      hkBool m_allowIntegrationOfIslandsWithoutConstraintsInASeparateJob;
      unsigned int m_minDesiredIslandSize;
      hkCriticalSection *m_modifyConstraintCriticalSection;
      int m_isLocked;
      hkCriticalSection *m_islandDirtyListCriticalSection;
      hkCriticalSection *m_propertyMasterLock;
      hkBool m_wantSimulationIslands;
      float m_snapCollisionToConvexEdgeThreshold;
      float m_snapCollisionToConcaveEdgeThreshold;
      hkBool m_enableToiWeldRejection;
      hkBool m_wantDeactivation;
      hkBool m_shouldActivateOnRigidBodyTransformChange;
      float m_deactivationReferenceDistance;
      float m_toiCollisionResponseRotateNormal;
      int m_maxSectorsPerCollideTask;
      hkBool m_processToisMultithreaded;
      int m_maxEntriesPerToiCollideTask;
      int m_maxNumToiCollisionPairsSinglethreaded;
      hkEnum<hkpWorldCinfo::SimulationType, int> m_simulationType;
      float m_numToisTillAllowedPenetrationSimplifiedToi;
      float m_numToisTillAllowedPenetrationToi;
      float m_numToisTillAllowedPenetrationToiHigher;
      float m_numToisTillAllowedPenetrationToiForced;
      unsigned int m_lastEntityUid;
      unsigned int m_lastIslandUid;
      unsigned int m_lastConstraintUid;
      hkArray<hkpPhantom *,hkContainerHeapAllocator> m_phantoms;
      hkArray<hkpActionListener *,hkContainerHeapAllocator> m_actionListeners;
      hkArray<hkpEntityListener *,hkContainerHeapAllocator> m_entityListeners;
      hkArray<hkpPhantomListener *,hkContainerHeapAllocator> m_phantomListeners;
      hkArray<hkpConstraintListener *,hkContainerHeapAllocator> m_constraintListeners;
      hkArray<hkpWorldDeletionListener *,hkContainerHeapAllocator> m_worldDeletionListeners;
      hkArray<hkpIslandActivationListener *,hkContainerHeapAllocator> m_islandActivationListeners;
      hkArray<hkpWorldPostSimulationListener *,hkContainerHeapAllocator> m_worldPostSimulationListeners;
      hkArray<hkpWorldPostIntegrateListener *,hkContainerHeapAllocator> m_worldPostIntegrateListeners;
      hkArray<hkpWorldPostCollideListener *,hkContainerHeapAllocator> m_worldPostCollideListeners;
      hkArray<hkpIslandPostIntegrateListener *,hkContainerHeapAllocator> m_islandPostIntegrateListeners;
      hkArray<hkpIslandPostCollideListener *,hkContainerHeapAllocator> m_islandPostCollideListeners;
      hkArray<hkpContactListener *,hkContainerHeapAllocator> m_contactListeners;
      hkArray<hkpContactImpulseLimitBreachedListener *,hkContainerHeapAllocator> m_contactImpulseLimitBreachedListeners;
      hkpViolatedConstraintArray *m_violatedConstraintArray;
      hkpBroadPhaseBorder *m_broadPhaseBorder;
      hkpCollisionCallbackUtil *m_collisionCallbackUtil;
      struct hkdWorld *m_destructionWorld;
      hkpWorldDynamicsStepInfo m_dynamicsStepInfo;
      hkVector4 m_broadPhaseExtents[2];
      int m_broadPhaseNumMarkers;
      int m_sizeOfToiEventQueue;
      int m_broadPhaseQuerySize;
      int m_broadPhaseUpdateSize;
      hkEnum<hkpWorldCinfo::ContactPointGeneration, signed char> m_contactPointGeneration;
  };

  static_assert(sizeof(hkpWorld) == 0x350, "hkpWorld has wrong size");
  
} // namespace CommonLib
