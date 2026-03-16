#pragma once
#include "Bethesda/BSSimpleList.hpp"

class SpellDispelData;

class MagicTarget
{
  public:
    MagicTarget();
    virtual ~MagicTarget();

    bool bShowTargetStats;
    bool bUpdating;
    BSSimpleList<SpellDispelData*> PostUpdateDispelList;
};

static_assert(sizeof(MagicTarget) == 0x10, "MagicTarget has wrong size");
