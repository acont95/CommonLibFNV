#pragma once
#include "Gamebryo/NiPoint3.hpp"

class TESObjectREFR;

class TeleportLink
{
  public:
    TeleportLink();
    ~TeleportLink();

    TESObjectREFR *pDoor;
    NiPoint3 DoorTeleportLocation;
};

static_assert(sizeof(TeleportLink) == 0x10, "TeleportLink has wrong size");
