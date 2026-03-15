#pragma once

class TESWeightForm
{
  public:
    TESWeightForm();
    virtual ~TESWeightForm();

    float fWeight;
};

static_assert(sizeof(TESWeightForm) == 0x8, "TESWeightForm has wrong size");
