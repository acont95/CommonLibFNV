#pragma once
#include <cstdint>
#include "Bethesda/BaseFormComponent.hpp"

class BGSClipRoundsForm : BaseFormComponent 
{
  public:
    BGSClipRoundsForm();
    virtual ~BGSClipRoundsForm();

    std::uint8_t cClipRounds;
};

static_assert(sizeof(BGSClipRoundsForm) == 0x8, "BGSClipRoundsForm has wrong size");
