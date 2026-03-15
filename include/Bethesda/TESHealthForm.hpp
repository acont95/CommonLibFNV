#pragma once
#include <cstdint>

class TESHealthForm
{
  public:
    TESHealthForm();
    virtual ~TESHealthForm();

    std::uint32_t iHealth;
};

static_assert(sizeof(TESHealthForm) == 0x8, "TESHealthForm has wrong size");
