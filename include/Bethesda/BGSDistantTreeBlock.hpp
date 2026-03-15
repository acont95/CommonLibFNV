#pragma once
#include "Bethesda/BSSimpleArray.hpp"
#include "Bethesda/BSMap.hpp"
#include "Bethesda/BGSTerrainNode.hpp"
#include "Bethesda/BGSDistantTreeBlockLoadTask.hpp"
#include "Bethesda/BSResizableTriShape.hpp"
#include "Gamebryo/NiTriShapeData.hpp"

class BGSDistantTreeBlock
{
  public:
    BGSDistantTreeBlock();
    ~BGSDistantTreeBlock();

    class TreeType
    {
      public:
        unsigned int uiNumber;
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
        unsigned int id;
        unsigned int uiGroup;
        bool bHidden;
    };

    class TreeGroup
    {
      public:
        BGSDistantTreeBlock::TreeType *pTreeType;
        NiPointer<BSResizableTriShape> spGeometry;
        BSSimpleArray<BGSDistantTreeBlock::InstanceData,1024> Instances;
        unsigned int uiNum;
        bool bShaderPropertyUpToDate;
    };

    NiPointer<BGSDistantTreeBlockLoadTask> spLoadTask;
    BSSimpleArray<BGSDistantTreeBlock::TreeGroup *,1024> TreeGroups;
    BSMap<unsigned int,BGSDistantTreeBlock::InstanceData *> InstanceMap;
    BSMap<unsigned int,BGSDistantTreeBlock::TreeGroup *> NextGroup;
    BSSimpleArray<unsigned int,1024> TreesQueuedToHide;
    BGSTerrainNode *pNode;
    bool bDoneLoading;
    bool bAttached;
};

static_assert(sizeof(BGSDistantTreeBlock) == 0x4C, "BGSDistantTreeBlock has wrong size");
