#pragma once

class NavMeshClosedDoorInfo
{
  public:
    NavMeshClosedDoorInfo();
    ~NavMeshClosedDoorInfo();

    unsigned int DoorFormID;
    unsigned __int16 iTriangleIndex;
};

static_assert(sizeof(NavMeshClosedDoorInfo) == 0x8, "NavMeshClosedDoorInfo has wrong size");
