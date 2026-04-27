#pragma once
#include <cstdint>

namespace CommonLib {

  class BSOcclusionQuery;

  class SunOcclusionTest
  {
    public:

      BSOcclusionQuery* pOcclusionQuery;
      bool bWaiting;
      float fPercentOccluded;
      std::uint32_t uiPixelCount;
      std::uint32_t uiFrameCount;
  };

  static_assert(sizeof(SunOcclusionTest) == 0x14, "SunOcclusionTest has wrong size");
  
} // namespace CommonLib
