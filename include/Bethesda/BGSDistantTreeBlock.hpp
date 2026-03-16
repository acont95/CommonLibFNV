#pragma once
#include <cstdint>
#include "Bethesda/BSSimpleArray.hpp"
#include "Bethesda/BSMap.hpp"
#include "Bethesda/BGSDistantTreeBlockLoadTask.hpp"
#include "Bethesda/BSResizableTriShape.hpp"
#include "Gamebryo/NiTriShapeData.hpp"

namespace CommonLib {

  class BGSTerrainNode;

  class BGSDistantTreeBlock
  {
    public:
      BGSDistantTreeBlock();
      ~BGSDistantTreeBlock();

      class TreeType
      {
        public:
          std::uint32_t uiNumber;
          float fWidth;
          float fHeight;
          float u0;
          float v0;
          float u1;
          float v1;
          NiPointer<NiTriShapeData> spSharedModelData;
      };

      class InstanceData
      {
        public:
          NiPoint3 Pos;
          float fRotZ;
          float fScale;
          std::uint32_t id;
          std::uint32_t uiGroup;
          bool bHidden;
      };

      class TreeGroup
      {
        public:
          BGSDistantTreeBlock::TreeType *pTreeType;
          NiPointer<BSResizableTriShape> spGeometry;
          BSSimpleArray<BGSDistantTreeBlock::InstanceData,1024> Instances;
          std::uint32_t uiNum;
          bool bShaderPropertyUpToDate;
      };

      NiPointer<BGSDistantTreeBlockLoadTask> spLoadTask;
      BSSimpleArray<BGSDistantTreeBlock::TreeGroup *,1024> TreeGroups;
      BSMap<std::uint32_t,BGSDistantTreeBlock::InstanceData *> InstanceMap;
      BSMap<std::uint32_t,BGSDistantTreeBlock::TreeGroup *> NextGroup;
      BSSimpleArray<std::uint32_t,1024> TreesQueuedToHide;
      BGSTerrainNode *pNode;
      bool bDoneLoading;
      bool bAttached;
  };

  static_assert(sizeof(BGSDistantTreeBlock) == 0x4C, "BGSDistantTreeBlock has wrong size");
  
} // namespace CommonLib
