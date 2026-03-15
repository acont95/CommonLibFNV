#pragma once
#include "Bethesda/BGSDistantTreeBlock.hpp"
#include "Bethesda/QueuedFileEntry.hpp"

class BGSDistantTreeBlockLoadTask : QueuedFileEntry
{
  public:
    BGSDistantTreeBlockLoadTask();
    virtual ~BGSDistantTreeBlockLoadTask();

    BGSDistantTreeBlock *pBlock;
    bool bFinishedQueuing;
    int iX;
    int iY;
    int iLevel;
    bool bCanceled;
    bool bFileExists;
};

static_assert(sizeof(BGSDistantTreeBlockLoadTask) == 0x48, "BGSDistantTreeBlockLoadTask has wrong size");
