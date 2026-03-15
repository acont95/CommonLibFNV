#pragma once
#include "Bethesda/TESCondition.hpp"
#include "Bethesda/TESObjectREFR.hpp"
#include "Bethesda/TeleportPath.hpp"

class TESQuestTarget
{
  public:
    TESQuestTarget();
    ~TESQuestTarget();

    unsigned __int8 cFlags;
    TESCondition objConditions;
    TESObjectREFR *m_pTargetRef;
    TeleportPath m_TargetPath;
};

static_assert(sizeof(TESQuestTarget) == 0x48, "TESQuestTarget has wrong size");
