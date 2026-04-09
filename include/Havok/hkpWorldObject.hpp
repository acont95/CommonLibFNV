#pragma once
#include <cstdint>
#include "Havok/hkReferencedObject.hpp"
#include "Havok/hkpLinkedCollidable.hpp"
#include "Havok/hkMultiThreadCheck.hpp"
#include "Havok/hkStringPtr.hpp"
#include "Havok/hkArray.hpp"
#include "Havok/hkpProperty.hpp"

namespace CommonLib {

  class hkpWorld;
  class hkContainerHeapAllocator;

  class hkpWorldObject : public hkReferencedObject
  {
    public:
      hkpWorldObject();
      virtual ~hkpWorldObject();

      hkpWorld *m_world;
      unsigned int m_userData;
      hkpLinkedCollidable m_collidable;
      hkMultiThreadCheck m_multiThreadCheck;
      hkStringPtr m_name;
      hkArray<hkpProperty, hkContainerHeapAllocator> m_properties;
      hkReferencedObject *m_aiData;
      void *m_treeData;
  };

  static_assert(sizeof(hkpWorldObject) == 0x8C, "hkpWorldObject has wrong size");
  
} // namespace CommonLib
