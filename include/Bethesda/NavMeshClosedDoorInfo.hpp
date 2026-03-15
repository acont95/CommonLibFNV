#pragma once
#include <cstdint>

class NavMeshClosedDoorInfo
{
  public:
    NavMeshClosedDoorInfo();
    ~NavMeshClosedDoorInfo();

    std::uint32_t DoorFormID;
    std::uint16_t iTriangleIndex;
};

static_assert(sizeof(NavMeshClosedDoorInfo) == 0x8, "NavMeshClosedDoorInfo has wrong size");
