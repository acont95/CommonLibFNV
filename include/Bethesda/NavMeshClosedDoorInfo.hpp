#pragma once
#include <cstdint>

class NavMeshClosedDoorInfo
{
  public:
    NavMeshClosedDoorInfo();
    ~NavMeshClosedDoorInfo();

    unsigned int DoorFormID;
    std::uint16_t iTriangleIndex;
};

static_assert(sizeof(NavMeshClosedDoorInfo) == 0x8, "NavMeshClosedDoorInfo has wrong size");
