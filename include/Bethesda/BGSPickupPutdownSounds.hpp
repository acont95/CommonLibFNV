#pragma once
#include "Bethesda/TESSound.hpp"

class BGSPickupPutdownSounds : public BaseFormComponent
{
  public:
    BGSPickupPutdownSounds();
    virtual ~BGSPickupPutdownSounds();

    TESSound *pPickupSound;
    TESSound *pPutdownSound;
};

static_assert(sizeof(BGSPickupPutdownSounds) == 0xC, "BGSPickupPutdownSounds has wrong size");
