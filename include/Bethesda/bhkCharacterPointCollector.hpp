#pragma once
#include <cstdint>
#include "Havok/hkArray.hpp"
#include "Havok/hkpAllCdPointCollector.hpp"

namespace CommonLib {

  class hkpWorldObject;
  class hkContainerHeapAllocator;
  class hkpRootCdPoint;

  class alignas(16) bhkCharacterPointCollector : public hkpAllCdPointCollector
  {
    public:
      bhkCharacterPointCollector();
      virtual ~bhkCharacterPointCollector();

      enum bhkCollisionObjectState : std::int32_t
      {
        COLLISION_OBJECT_NEW = 0x0,
        COLLISION_OBJECT_REMOVED = 0x1,
        COLLISION_OBJECT_UNTOUCHED = 0x2,
      };
      
      const bhkCharacterPointCollector *pStartCollector;
      hkArray<hkpWorldObject*, hkContainerHeapAllocator> m_collidingObjects;
      hkArray<bhkCollisionObjectState, hkContainerHeapAllocator> m_collisionStates;
      hkArray<hkpRootCdPoint, hkContainerHeapAllocator> m_collisionPoints;
  };

  static_assert(sizeof(bhkCharacterPointCollector) == 0x3D0, "bhkCharacterPointCollector has wrong size");
  
} // namespace CommonLib
