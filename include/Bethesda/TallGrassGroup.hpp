#pragma once
#include <cstdint>
#include "Bethesda/BSMultiBoundNode.hpp"
#include "Bethesda/TallGrassShaderProperty.hpp"

namespace CommonLib {

  class TallGrassGroup
  {
    public:
      TallGrassGroup();
      ~TallGrassGroup();

      struct GrassInstanceData
      {
        float fXPos;
        float fYPos;
        float fZPos;
        float fColor;
      };

      NiPointer<NiGeometry> spGrassGeometry;
      NiPointer<BSMultiBoundNode> spMBGrassNode;
      NiPointer<TallGrassShaderProperty::CachedGeometry> spCachedGeometry;
      NiPointer<TallGrassShaderProperty> spGrassProperty;
      std::uint16_t iMaxInstanceCount;
      std::uint16_t iInstanceCount;
      GrassInstanceData *pInstanceData;
      std::int32_t *plTerrainChunkSeed;
      TallGrassShaderProperty::GrassParam kGrassParam;
      std::int32_t iCellCoord[2];
      bool bLowDetail;
  };

  static_assert(sizeof(TallGrassGroup) == 0x48, "TallGrassGroup has wrong size");
  
} // namespace CommonLib
