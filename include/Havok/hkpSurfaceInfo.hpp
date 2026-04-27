#pragma once
#include <cstdint>
#include "Havok/hkVector4.hpp"
#include "Havok/hkBool.hpp"

namespace CommonLib {

  class hkpSurfaceInfo
  {
    public:

      enum SupportedState : std::int32_t
      {
        UNSUPPORTED = 0x0,
        SLIDING = 0x1,
        SUPPORTED = 0x2,
      };

      hkpSurfaceInfo::SupportedState m_supportedState;
      hkVector4 m_surfaceNormal;
      hkVector4 m_surfaceVelocity;
      float m_surfaceDistanceExcess;
      hkBool m_surfaceIsDynamic;
  };

  static_assert(sizeof(hkpSurfaceInfo) == 0x40, "hkpSurfaceInfo has wrong size");
  
} // namespace CommonLib
