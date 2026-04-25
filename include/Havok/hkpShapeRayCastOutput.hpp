#pragma once
#include <cstdint>
#include "Havok/hkpShapeRayCastCollectorOutput.hpp"

namespace CommonLib {

  class alignas(16) hkpShapeRayCastOutput : public hkpShapeRayCastCollectorOutput
  {
    public:
      hkpShapeRayCastOutput();
      ~hkpShapeRayCastOutput();

      std::uint32_t m_shapeKeys[8];
      std::int32_t m_shapeKeyIndex;
  };

  static_assert(sizeof(hkpShapeRayCastOutput) == 0x50, "hkpShapeRayCastOutput has wrong size");
  
} // namespace CommonLib
