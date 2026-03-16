#pragma once
#include <cstdint>
#include "Bethesda/QueuedFileEntry.hpp"

class BGSDistantTreeBlock;

class BGSDistantTreeBlockLoadTask : public QueuedFileEntry
{
  public:
    BGSDistantTreeBlockLoadTask();
    virtual ~BGSDistantTreeBlockLoadTask();

    BGSDistantTreeBlock *pBlock;
    bool bFinishedQueuing;
    std::int32_t iX;
    std::int32_t iY;
    std::int32_t iLevel;
    bool bCanceled;
    bool bFileExists;
};

static_assert(sizeof(BGSDistantTreeBlockLoadTask) == 0x48, "BGSDistantTreeBlockLoadTask has wrong size");
