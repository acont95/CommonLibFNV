#pragma once

class TESValueForm
{
  public:
    TESValueForm();
    virtual ~TESValueForm();

    unsigned int iValue;
};

static_assert(sizeof(TESValueForm) == 0x8, "TESValueForm has wrong size");
