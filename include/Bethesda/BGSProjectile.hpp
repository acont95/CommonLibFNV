#pragma once
#include "Types.hpp"
#include "Bethesda/BGSProjectileData.hpp"
#include "Bethesda/TESModel.hpp"
#include "Bethesda/TESBoundObject.hpp"
#include "Bethesda/TESFullName.hpp"
#include "Bethesda/BGSPreloadable.hpp"
#include "Bethesda/BGSDestructibleObjectForm.hpp"

class BGSProjectile  : 
  public TESBoundObject, 
  public TESFullName, 
  public TESModel, 
  public BGSPreloadable, 
  public BGSDestructibleObjectForm
{
  public:
    BGSProjectile();
    ~BGSProjectile();

    BGSProjectileData Data;
    TESModel MuzzleFlashModel;
    SOUND_LEVEL eSoundLevel;
};

static_assert(sizeof(BGSProjectile) == 0xD0);
