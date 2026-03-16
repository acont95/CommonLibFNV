#pragma once
#include <cstdint>
#include "Gamebryo/NiPoint3.hpp"

namespace CommonLib {

  class BSOcclusionQuery;

  class ReferenceVolume
  {
    public:
      ReferenceVolume();
      ~ReferenceVolume();

      NiPoint3 Center;
      float fRadius;
      std::uint32_t uiReferenceID;
      BSOcclusionQuery *pOcclusionQuery;
      bool bOccluded;
      bool bWaiting;
      bool bPerformTest;
      std::uint32_t uiPixelCount;
  };

  static_assert(sizeof(ReferenceVolume) == 0x20);
  
} // namespace CommonLib
