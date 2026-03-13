#pragma once

class TESChildCell
{
  public:
    TESChildCell();
    virtual ~TESChildCell();
};

static_assert(sizeof(TESChildCell) == 0x4, "TESChildCell has wrong size");
