#pragma once
#include "Gamebryo/NiObject.hpp"

class TESObjectCELL;

class BSTempEffect : public NiObject
{
  public:
    BSTempEffect();
    ~BSTempEffect();

    float fLifetime;
    TESObjectCELL* pCell;
    float fAge;
    bool bInitialized;
};

static_assert(sizeof(BSTempEffect) == 0x18, "BSTempEffect has wrong size");
