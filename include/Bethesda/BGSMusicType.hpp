#pragma once
#include "Bethesda/TESForm.hpp"
#include "Bethesda/BGSPlaceableWaterData.hpp"

class BGSMusicType : TESForm, TESSoundFile
{
  public:
    BGSMusicType();
    virtual ~BGSMusicType();

    class MusicFileEntry
    {
      char cFilename[260];
    };

    float fAttenuation;
    BSSimpleList<MusicFileEntry *> pMusicFileList;
    unsigned int iLastSelection;
};

static_assert(sizeof(BGSMusicType) == 0x34, "BGSMusicType has wrong size");
