#pragma once
#include <cstdint>
#include "Bethesda/BSSimpleArray.hpp"
#include "Bethesda/bhkRigidBody.hpp"
#include "Gamebryo/NiTriShape.hpp"

namespace CommonLib {

  class NavMeshInfo;
  class ReferenceObstacleArray;

  class ObstacleData : public NiRefObject
  {
    public:
      ObstacleData();
      virtual ~ObstacleData();

      ReferenceObstacleArray *spParentArray;
      NiPointer<bhkRigidBody> pRigidBody;
      NiPoint3 Center;
      NiMatrix3 Orientation;
      NiPoint3 BoxMin;
      NiPoint3 BoxMax;
      NiPoint3 aabbMin;
      NiPoint3 aabbMax;
      std::uint32_t iLastUpdateTime;
      bool bActive;
      BSSimpleArray<NavMeshInfo *,1024> Navmeshes;
      NiPointer<NiTriShape> sp3DNode;
  };

  static_assert(sizeof(ObstacleData) == 0x8C, "ObstacleData has wrong size");
  
} // namespace CommonLib
