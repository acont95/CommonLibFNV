#pragma once
#include <cstdint>

namespace CommonLib {

  class D3DQuery;

  class BSOcclusionQuery
  {
    public:

      std::uint32_t uiNumTiles;
      D3DQuery* pQuery;
  };

  static_assert(sizeof(BSOcclusionQuery) == 0x8, "BSOcclusionQuery has wrong size");
  
} // namespace CommonLib
