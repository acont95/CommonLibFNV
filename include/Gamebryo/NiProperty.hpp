#pragma once
#include "Gamebryo/NiObjectNET.hpp"

class NiProperty : NiObjectNET
{
  public:
    NiProperty();
    ~NiProperty();
};

static_assert(sizeof(NiProperty) == 0x18, "NiProperty has wrong size");
