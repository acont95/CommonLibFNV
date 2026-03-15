#pragma once
#include <cstdint>
#include "Bethesda/D3DQuery.hpp"

class BSOcclusionQuery
{
  public:
    BSOcclusionQuery();
    ~BSOcclusionQuery();

    std::uint32_t uiNumTiles;
    D3DQuery* pQuery;
};

static_assert(sizeof(BSOcclusionQuery) == 0x8, "BSOcclusionQuery has wrong size");
