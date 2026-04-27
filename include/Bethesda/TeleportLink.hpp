#pragma once
#include "Gamebryo/NiPoint3.hpp"

namespace CommonLib {

  class TESObjectREFR;

  class TeleportLink
  {
    public:

      TESObjectREFR *pDoor;
      NiPoint3 DoorTeleportLocation;
  };

  static_assert(sizeof(TeleportLink) == 0x10, "TeleportLink has wrong size");
  
} // namespace CommonLib
