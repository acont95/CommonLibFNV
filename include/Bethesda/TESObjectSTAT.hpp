#pragma once
#include "Bethesda/TESBoundObject.hpp"
#include "Bethesda/TESModelTextureSwap.hpp"

class TESSound;

class TESObjectSTAT : 
  public TESBoundObject, 
  public TESModelTextureSwap
{
  public:
    TESObjectSTAT();
    virtual ~TESObjectSTAT();

    char cPassThroughSoundIndex;
    TESSound *pRandomSound;
};

static_assert(sizeof(TESObjectSTAT) == 0x58, "TESObjectSTAT has wrong size");
