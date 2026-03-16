#pragma once
#include <cstdint>
#include "Bethesda/BSSimpleArray.hpp"
#include "Gamebryo/NiPoint3.hpp"

namespace CommonLib {

  class NavMeshGrid
  {
    public:
      NavMeshGrid();
      ~NavMeshGrid();

      std::uint32_t iGridSize;
      float fColumnSectionLen;
      float fRowSectionLen;
      NiPoint3 GridBoundsMin;
      NiPoint3 GridBoundsMax;
      BSSimpleArray<unsigned short,1024> *GridData;
  };

  static_assert(sizeof(NavMeshGrid) == 0x28, "NavMeshGrid has wrong size");
  
} // namespace CommonLib
