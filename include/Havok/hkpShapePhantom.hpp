#pragma once
#include "Havok/hkpPhantom.hpp"
#include "Havok/hkMotionState.hpp"

namespace CommonLib {

  class hkpShapePhantom : public hkpPhantom 
  {
    public:
      hkMotionState m_motionState;
  };

  static_assert(sizeof(hkpShapePhantom) == 0x160, "hkpShapePhantom has wrong size");
  
} // namespace CommonLib
