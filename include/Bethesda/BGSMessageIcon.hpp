#pragma once
#include "Bethesda/TESIcon.hpp"

class BGSMessageIcon
{
  public:
    BGSMessageIcon();
    virtual ~BGSMessageIcon();

    TESIcon Icon;
};

static_assert(sizeof(BGSMessageIcon) == 0x10, "BGSMessageIcon has wrong size");
