#pragma once
#include "Bethesda/TESForm.hpp"
#include "Bethesda/ImageSpaceParameterData.hpp"

class TESImageSpace : TESForm
{
  public:
    TESImageSpace();
    virtual ~TESImageSpace();

    ImageSpaceParameterData Data;
};

static_assert(sizeof(TESImageSpace) == 0xB0, "TESImageSpace has wrong size");
