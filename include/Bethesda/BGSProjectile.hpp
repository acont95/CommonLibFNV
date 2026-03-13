#pragma once
#include "Types.hpp"
#include "Bethesda/BGSProjectileData.hpp"
#include "Bethesda/TESModel.hpp"
#include "Bethesda/TESFullName.hpp"
#include "Bethesda/TESBoundObject.hpp"
#include "Bethesda/BGSPreloadable.hpp"
#include "Bethesda/BGSDestructibleObjectForm.hpp"

class BGSProjectile  : TESBoundObject, TESFullName, TESModel, BGSPreloadable, BGSDestructibleObjectForm
{
  public:
    BGSProjectile();
    ~BGSProjectile();

    BGSProjectileData Data;
    TESModel MuzzleFlashModel;
    SOUND_LEVEL eSoundLevel;
};
