#pragma once
#include <cstdint>
#include "Gamebryo/NiNode.hpp"

class BGSTerrainManager;
class BGSTerrainChunk;
class BGSDistantObjectBlock;
class BGSDistantTreeBlock;
class BGSTerrainNode;

class BGSTerrainNode
{
  public:
    BGSTerrainNode();
    ~BGSTerrainNode();

    enum PARENT_POSITION
    {
      PP_TOPLEVEL = 0x0,
      PP_UPPER_LEFT = 0x1,
      PP_UPPER_RIGHT = 0x2,
      PP_LOWER_LEFT = 0x3,
      PP_LOWER_RIGHT = 0x4,
    };

    enum DATA_TO_UNLOAD
    {
      UNLOAD_TERRAIN_ONLY = 0x1,
      UNLOAD_OBJECTS_ONLY = 0x2,
      UNLOAD_TREES_ONLY = 0x4,
      UNLOAD_ALL = 0x7,
    };

    BGSTerrainManager *pManager;
    std::uint32_t iLevel;
    std::int16_t sBaseCellX;
    std::int16_t sBaseCellY;
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
    std::uint32_t uiFadeStartTime;
    bool bTexFading;
    PARENT_POSITION ParentPosition;
    bool bPersistentNode;
    bool bSplitNode;
};

static_assert(sizeof(BGSTerrainNode) == 0x60, "BGSTerrainNode has wrong size");
