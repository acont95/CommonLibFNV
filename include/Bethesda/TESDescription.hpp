#pragma once
#include <cstdint>
#include "Bethesda/BaseFormComponent.hpp"

class TESDescription : public BaseFormComponent
{
  public:
    TESDescription();
    ~TESDescription();

    std::uint32_t lFileOffset;
};


static_assert(sizeof(TESDescription) == 0x8, "TESDescription has wrong size");
