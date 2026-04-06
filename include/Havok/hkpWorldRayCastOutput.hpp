#pragma once
#include <cstdint>
#include "Havok/hkpShapeRayCastOutput.hpp"

namespace CommonLib {

  class hkpCollidable;

  class hkpWorldRayCastOutput : public hkpShapeRayCastOutput
  {
    public:
      hkpWorldRayCastOutput();
      ~hkpWorldRayCastOutput();

      const hkpCollidable *m_rootCollidable;
  };

  static_assert(sizeof(hkpWorldRayCastOutput) == 0x60, "hkpWorldRayCastOutput has wrong size");
  
} // namespace CommonLib
