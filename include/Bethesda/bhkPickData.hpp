#pragma once
#include "Havok/hkpWorldRayCastInput.hpp"
#include "Havok/hkpWorldRayCastOutput.hpp"
#include "Havok/hkVector4.hpp"

namespace CommonLib {

  class hkpClosestRayHitCollector;
  class hkpAllRayHitCollector;

  class bhkPickData : public hkpWorldRayCastInput, public hkpWorldRayCastOutput
  {
    public:
      bhkPickData();
      ~bhkPickData();

      hkVector4 hkLength;
      char *pCache;
      hkpClosestRayHitCollector *pCloseCollector;
      hkpAllRayHitCollector *pAllCollector;
      bool bPickFailed;
  };

  static_assert(sizeof(bhkPickData) == 0xB0, "bhkPickData has wrong size");
  
} // namespace CommonLib
