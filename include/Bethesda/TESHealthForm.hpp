#pragma once

class TESHealthForm
{
  public:
    TESHealthForm();
    virtual ~TESHealthForm();

    unsigned int iHealth;
};

static_assert(sizeof(TESHealthForm) == 0x8, "TESHealthForm has wrong size");
