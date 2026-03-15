#pragma once
#include "Bethesda/BGSTerrainManager.hpp"
#include "Bethesda/BGSTerrainChunk.hpp"
#include "Bethesda/BGSDistantObjectBlock.hpp"
#include "Bethesda/BGSDistantTreeBlock.hpp"
#include "Bethesda/BGSTerrainNode.hpp"
#include "Gamebryo/NiNode.hpp"
#include "Gamebryo/NiPoint3.hpp"

class BGSTerrainNode
{
  public:
    BGSTerrainNode();
    ~BGSTerrainNode();

    enum PARENT_POSITION : __int32
    {
      PP_TOPLEVEL = 0x0,
      PP_UPPER_LEFT = 0x1,
      PP_UPPER_RIGHT = 0x2,
      PP_LOWER_LEFT = 0x3,
      PP_LOWER_RIGHT = 0x4,
    };

    enum DATA_TO_UNLOAD : __int32
    {
      UNLOAD_TERRAIN_ONLY = 0x1,
      UNLOAD_OBJECTS_ONLY = 0x2,
      UNLOAD_TREES_ONLY = 0x4,
      UNLOAD_ALL = 0x7,
    };

    BGSTerrainManager *pManager;
    unsigned int iLevel;
    __int16 sBaseCellX;
    __int16 sBaseCellY;
    bool bHasGeometry;
    bool bChildrenLoaded;
    BGSTerrainChunk *pChunk;
    BGSDistantObjectBlock *pBlock;
    BGSDistantTreeBlock *pTrees;
    NiNode *pSceneNode;
    BGSTerrainNode *pChildren[4];
    BGSTerrainNode *pParent;
    NiPoint3 Center;
    float fCornerRadius;
    float fSplitDistance;
    float fStartMorphDistance;
    float fEndMorphDistance;
    unsigned int uiFadeStartTime;
    bool bTexFading;
    PARENT_POSITION ParentPosition;
    bool bPersistentNode;
    bool bSplitNode;
};

static_assert(sizeof(BGSTerrainNode) == 0x60, "BGSTerrainNode has wrong size");
