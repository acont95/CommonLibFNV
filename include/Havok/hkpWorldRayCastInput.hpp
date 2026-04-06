#pragma once
#include <cstdint>
#include "Havok/hkVector4.hpp"
#include "Havok/hkBool.hpp"

namespace CommonLib {

  class hkpWorldRayCastInput
  {
    public:
      hkpWorldRayCastInput();
      ~hkpWorldRayCastInput();

      hkVector4 m_from;
      hkVector4 m_to;
      hkBool m_enableShapeCollectionFilter;
      std::uint32_t m_filterInfo;
  };

  static_assert(sizeof(hkpWorldRayCastInput) == 0x30, "hkpWorldRayCastInput has wrong size");
  
} // namespace CommonLib
