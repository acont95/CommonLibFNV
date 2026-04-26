#pragma once
#include <cstdint>
#include "Types.hpp"
#include "Bethesda/bhkCharacterProxy.hpp"
#include "Bethesda/bhkCharacterListener.hpp"
#include "Bethesda/bhkShapePhantom.hpp"
#include "Bethesda/bhkCollisionBox.hpp"
#include "Bethesda/bhkShape.hpp"
#include "Bethesda/BSSimpleList.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Havok/hkpCharacterContext.hpp"
#include "Havok/hkVector4.hpp"
#include "Havok/hkStepInfo.hpp"
#include "Havok/hkRefPtr.hpp"
#include "Havok/hkArray.hpp"
#include "Havok/hkContainerHeapAllocator.hpp"
#include "Havok/hkpSurfaceInfo.hpp"


namespace CommonLib {

  class hkpRigidBody;
  class hkpCharacterProxy;
  class hkpRootCdPoint;
  class DamageImpactData;

  enum SHAPE_TYPES : std::int32_t
  {
    ST_CAPSULE = 0x0,
    ST_CUSTOM = 0x0,
    ST_CONVEX = 0x1,
    ST_NUMTYPES = 0x2,
  };

  class alignas(16) bhkCharacterController : 
    public bhkCharacterProxy, 
    public hkpCharacterContext, 
    public bhkCharacterListener, 
    public hkpSurfaceInfo
  {
    public:
      bhkCharacterController();
      virtual ~bhkCharacterController();

      enum CHARACTER_SIZE : std::int32_t
      {
        CS_NORMAL = 0x0,
        CS_SIZED = 0x1,
        CS_SIZING = 0x2,
      };

      enum CHARACTER_FLAGS : std::int32_t
      {
        HITSTEPS = 0x40,
        HITDAMAGE = 0x80,
        HITFLAGS = 0xC0,
        SUPPORT = 0x100,
        SUPPORT2 = 0x200,
        CANJUMP = 0x400,
        CHASEBIP = 0x800,
        FOLLOWRAGDOLL = 0x1000,
        JUMPING = 0x2000,
        NOTPUSHABLE = 0x4000,
        DEBUGDISP = 0x8000,
        CHECKSUPPORT = 0x10000,
        ON_ELEVATOR = 0x20000,
        FAR_AWAY = 0x40000,
        QUICK_SIMULATE = 0x100000,
        RECORD_HITS = 0x200000,
        WAIT_FOR_BATCH_ADD = 0x400000,
        ON_PLATFORM = 0x800000,
        ON_STAIRS = 0x1000000,
        CAN_PITCH = 0x2000000,
        CAN_ROLL = 0x4000000,
        NO_CHARACTER_COLLISIONS = 0x8000000,
        NOTPUSHABLE_PERMANENT = 0x10000000,
      };

      enum REFERENCE_SLOTS : std::int32_t
      {
        MOBOBJECT = 0x3E8,
        NiOBJECT = 0x3E9,
      };

      hkVector4 UpVec;
      hkVector4 ForwardVec;
      hkStepInfo StepInfo;
      hkVector4 OutVelocity;
      hkVector4 VelocityMod;
      hkVector4 Direction;
      hkpCharacterStateType eWantState;
      float fVelocityTime;
      float fRotMod;
      float fRotModTime;
      float fCalculatePitchTimer;
      float fAcrobatics;
      float fCenter;
      float fWaterHeight;
      float fJumpHeight;
      float fFallStartHeight;
      float fFallTime;
      float fGravity;
      float fPitchAngle;
      float fRollAngle;
      float fPitchMult;
      float fScale;
      float fSwimFloatHeight;
      float fActorHeight;
      float fSpeedPct;
      hkVector4 RotCenter;
      hkVector4 PushDelta;
      unsigned int iPushCount;
      NiPointer<bhkShapePhantom> spShapePhantom;
      NiPointer<bhkCollisionBox> spCollisionBox;
      SHAPE_TYPES eShapeType;
      SHAPE_TYPES eSizedShapeType;
      NiPointer<bhkShape> spShapes[2];
      hkVector4 FrontBack[4];
      float fRadius;
      float fHeight;
      float fDestRadius;
      float fLODDistance;
      bhkCharacterController::CHARACTER_SIZE eSize;
      unsigned int iPriority;
      int iSupportCount;
      hkRefPtr<hkpRigidBody> spSupportBody;
      bool bFakeSupport;
      hkVector4 FakeSupportStart;
      hkRefPtr<hkpRigidBody> spBumpedBody;
      float fBumpedForce;
      hkRefPtr<hkpCharacterProxy> spBumpedCharProxy;
      hkArray<hkpRootCdPoint,hkContainerHeapAllocator> LastManifold;
      BSSimpleList<DamageImpactData *> DamageImpacts;
  };

  static_assert(sizeof(bhkCharacterController) == 0x650, "bhkAction has wrong size");
  
} // namespace CommonLib
