#pragma once
#include "Bethesda/TESForm.hpp"

struct ENCOUNTER_ZONE_DATA
{
  TESForm *pZoneOwner;
  char iOwnerRank;
  unsigned __int8 cMinLevel;
  char cFlags;
};

struct ENCOUNTER_ZONE_GAME_DATA
{
  unsigned int iDetachTime;
  unsigned int iAttachTime;
  unsigned int iResetTime;
  unsigned __int16 sZoneLevel;
};

class BGSEncounterZone : TESForm
{
  public:
    BGSEncounterZone();
    virtual ~BGSEncounterZone();

    ENCOUNTER_ZONE_DATA Data;
    ENCOUNTER_ZONE_GAME_DATA GameData;
};

static_assert(sizeof(BGSEncounterZone) == 0x30, "BGSEncounterZone has wrong size");
