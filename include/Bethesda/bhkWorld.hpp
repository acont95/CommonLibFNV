#pragma once
#include <cstdint>
#include "Bethesda/bhkSerializable.hpp"
#include "Bethesda/BSSimpleList.hpp"
#include "Bethesda/ColorPair.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Havok/hkVector4.hpp"
#include "Havok/hkArray.hpp"

namespace CommonLib {

  class hkVisualDebugger;
  class bhkTrapListener;
  class bhkWaterListener;
  class bhkEntityListener;
  class hkpEntity;
  class hkpPhantom;
  class hkpAction;
  class hkpConstraintInstance;
  class hkContainerHeapAllocator;
  class hkpConstraintInstance;
  class bhkAction;

  class bhkWorld : public bhkSerializable
  {
    public:
      bhkWorld();
      virtual ~bhkWorld();

      hkVisualDebugger *pDebugger;
      bool bAdded;
      bool bEnabled;
      bool bDebugDisplay;
      std::uint32_t iBatchAdd;
      std::uint32_t iBatchRemove;
      bhkTrapListener *pTrapListener;
      bhkWaterListener *pWaterListener;
      bhkEntityListener *pAcousticSpaceListener;
      hkpEntity **pEntityBatch;
      std::uint32_t iEntityBatchCount;
      hkpPhantom **pPhantomBatch;
      std::uint32_t iPhantomBatchCount;
      hkpAction **pActionBatch;
      std::uint32_t iActionBatchCount;
      hkpConstraintInstance **pConstraintInstanceBatch;
      std::uint32_t iConstraintInstanceBatchCount;
      hkpEntity **pEntityRemoveBatch;
      std::uint32_t iEntityRemoveBatchCount;
      hkVector4 Origin;
      hkArray<bhkEntityListener*, hkContainerHeapAllocator> pEntityListenerA;
      hkArray<ColorPair, hkContainerHeapAllocator> DebugColorA;
      float fOriginalTau;
      float fOriginalDamping;
      BSSimpleList<NiPointer<bhkAction>> ActionList;
  };

  static_assert(sizeof(bhkWorld) == 0xA0, "bhkWorld has wrong size");
  
} // namespace CommonLib
