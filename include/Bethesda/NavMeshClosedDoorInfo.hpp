#pragma once
#include <cstdint>

namespace CommonLib {

  class NavMeshClosedDoorInfo
  {
    public:

      std::uint32_t DoorFormID;
      std::uint16_t iTriangleIndex;
  };

  static_assert(sizeof(NavMeshClosedDoorInfo) == 0x8, "NavMeshClosedDoorInfo has wrong size");
  
} // namespace CommonLib
