#pragma once
#include <cstdint>
#include "Bethesda/TESForm.hpp"

namespace CommonLib {

  struct ENCOUNTER_ZONE_DATA
  {
    TESForm *pZoneOwner;
    char iOwnerRank;
    std::uint8_t cMinLevel;
    char cFlags;
  };

  struct ENCOUNTER_ZONE_GAME_DATA
  {
    std::uint32_t iDetachTime;
    std::uint32_t iAttachTime;
    std::uint32_t iResetTime;
    std::uint16_t sZoneLevel;
  };

  class BGSEncounterZone : public TESForm
  {
    public:
      BGSEncounterZone();
      virtual ~BGSEncounterZone();

      ENCOUNTER_ZONE_DATA Data;
      ENCOUNTER_ZONE_GAME_DATA GameData;
  };

  static_assert(sizeof(BGSEncounterZone) == 0x30, "BGSEncounterZone has wrong size");
  
} // namespace CommonLib
