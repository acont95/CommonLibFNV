#pragma once
#include "Havok/hkpWorldObject.hpp"

namespace CommonLib {

  class hkpPhantomOverlapListener;
  class hkpPhantomListener;

  class hkpPhantom : public hkpWorldObject 
  {
    public:
      hkpPhantom();
      virtual ~hkpPhantom();

      hkArray<hkpPhantomOverlapListener*, hkContainerHeapAllocator> m_overlapListeners;
      hkArray<hkpPhantomListener*, hkContainerHeapAllocator> m_phantomListeners;
  };

  static_assert(sizeof(hkpPhantom) == 0xA4, "hkpPhantom has wrong size");
  
} // namespace CommonLib
