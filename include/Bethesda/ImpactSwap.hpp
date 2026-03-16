#pragma once

class BGSImpactData;
template <typename Key, typename Value>
class BSMap;

// Need to add type defines
class ImpactSwap
{
  public:
    ImpactSwap();
    ~ImpactSwap();

    BSMap<BGSImpactData *,BGSImpactData *> *pRemappedData[12];
    char pAltFootstepMaterialNames[10][30];
};

static_assert(sizeof(ImpactSwap) == 0x15C);
