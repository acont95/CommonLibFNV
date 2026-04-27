#pragma once
#include <cstdint>
#include "Havok/hkArray.hpp"
#include "Havok/hkpCollidable.hpp"

namespace CommonLib {

  class hkContainerHeapAllocator;
  class hkpAgentNnEntry;

  class hkpLinkedCollidable : public hkpCollidable
  {
    public:

      struct CollisionEntry
      {
        hkpAgentNnEntry *m_agentEntry;
        hkpLinkedCollidable *m_partner;
      };

      hkArray<CollisionEntry, hkContainerHeapAllocator> m_collisionEntries;
  };

  static_assert(sizeof(hkpLinkedCollidable) == 0x5C, "hkpLinkedCollidable has wrong size");
  
} // namespace CommonLib
