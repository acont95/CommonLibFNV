#pragma once
#include "Bethesda/TESBoundObject.hpp"

class TESBoundAnimObject : TESBoundObject
{
  public:
    TESBoundAnimObject();
    ~TESBoundAnimObject();
};

static_assert(sizeof(TESBoundAnimObject) == 0x30, "TESBoundAnimObject has wrong size");
