#pragma once
#include "Bethesda/BaseFormComponent.hpp"

class BGSClipRoundsForm : BaseFormComponent 
{
  public:
    BGSClipRoundsForm();
    virtual ~BGSClipRoundsForm();

    unsigned __int8 cClipRounds;
};

static_assert(sizeof(BGSClipRoundsForm) == 0x8, "BGSClipRoundsForm has wrong size");
