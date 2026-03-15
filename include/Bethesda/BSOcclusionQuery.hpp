#pragma once
#include "Bethesda/D3DQuery.hpp"

class BSOcclusionQuery
{
  public:
    BSOcclusionQuery();
    ~BSOcclusionQuery();

    unsigned int uiNumTiles;
    D3DQuery* pQuery;
};

static_assert(sizeof(BSOcclusionQuery) == 0x8, "BSOcclusionQuery has wrong size");
