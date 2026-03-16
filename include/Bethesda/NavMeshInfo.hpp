#pragma once
#include <cstdint>
#include "Bethesda/BSSimpleArray.hpp"
#include "Gamebryo/NiPoint3.hpp"

namespace CommonLib {

  class TESForm;
  class TESObjectREFR;
  class NavMesh;
  class NavMeshBounds;

  class NavMeshInfo
  {
    public:
      NavMeshInfo();
      ~NavMeshInfo();

      std::uint32_t NavMeshID;
      std::uint32_t ParentSpaceID;
      std::uint32_t uiFlags;
      std::int32_t iCellKey;
      NiPoint3 ApproxLocation;
      TESForm *pParentSpace;
      float fPreferredPercent;
      BSSimpleArray<NavMeshInfo *,1024> AdjacentNavMeshes;
      BSSimpleArray<NavMeshInfo *,1024> PreferredAdjacentNavMeshes;
      BSSimpleArray<TESObjectREFR *,1024> ConnectedDoors;
      NavMesh *pNavMesh;
      NavMeshBounds *pBounds;
  };

  static_assert(sizeof(NavMeshInfo) == 0x5C, "NavMeshInfo has wrong size");
  
} // namespace CommonLib
