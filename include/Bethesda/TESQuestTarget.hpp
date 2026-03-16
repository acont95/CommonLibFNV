#pragma once
#include <cstdint>
#include "Bethesda/TESCondition.hpp"
#include "Bethesda/TeleportPath.hpp"

class TESObjectREFR;

class TESQuestTarget
{
  public:
    TESQuestTarget();
    ~TESQuestTarget();

    std::uint8_t cFlags;
    TESCondition objConditions;
    TESObjectREFR *m_pTargetRef;
    TeleportPath m_TargetPath;
};

static_assert(sizeof(TESQuestTarget) == 0x48, "TESQuestTarget has wrong size");
