#pragma once
#include <cstdint>
#include "Havok/hkVector4.hpp"

namespace CommonLib {

  class alignas(16) hkpShapeRayCastCollectorOutput
  {
    public:

      hkVector4 m_normal;
      float m_hitFraction;
      std::int32_t m_extraInfo;
      std::int32_t m_pad[2];
  };

  static_assert(sizeof(hkpShapeRayCastCollectorOutput) == 0x20, "hkpShapeRayCastCollectorOutput has wrong size");
  
} // namespace CommonLib
