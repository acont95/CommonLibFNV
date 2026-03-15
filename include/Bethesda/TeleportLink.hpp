#pragma once
#include "Bethesda/TESObjectREFR.hpp"
#include "Gamebryo/NiPoint3.hpp"

class TeleportLink
{
  public:
    TeleportLink();
    ~TeleportLink();

    TESObjectREFR *pDoor;
    NiPoint3 DoorTeleportLocation;
};

static_assert(sizeof(TeleportLink) == 0x10, "TeleportLink has wrong size");
