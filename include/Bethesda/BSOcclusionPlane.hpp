#pragma once
#include "Bethesda/BSMultiBoundShape.hpp"
#include "Gamebryo/NiFrustumPlanes.hpp"
#include "Gamebryo/NiPoint2.hpp"
#include "Gamebryo/NiMatrix3.hpp"

namespace CommonLib {

  class NiAVObject;

  class BSOcclusionPlane : public NiObject
  {
    public:
      BSOcclusionPlane();
      virtual ~BSOcclusionPlane();

      NiPoint3 kCenter;
      NiPoint2 kHalfExtents;
      NiMatrix3 kRotation;
      BSMultiBoundShape::BSMBCullResult kCullResult;
      NiFrustumPlanes kCachedPlanes;
      NiPoint3 kCachedVertices[4];
      NiPoint3 kCachedViewPoint;
      bool bDirtyVertices;
      bool bDirtyPlanes;
      bool bDisabledPlanes[4];
      bool bTwoSided;
      BSOcclusionPlane* pLinkedPlanes[4];
  };

  static_assert(sizeof(BSOcclusionPlane) == 0xFC, "BSOcclusionPlane has wrong size");
  
} // namespace CommonLib
