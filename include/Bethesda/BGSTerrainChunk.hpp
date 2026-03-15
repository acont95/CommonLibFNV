#pragma once
#include "Bethesda/BGSTerrainNode.hpp"
#include "Bethesda/BSMultiBoundNode.hpp"
#include "Bethesda/TESObjectREFR.hpp"
#include "Bethesda/BGSTerrainChunkLoadTask.hpp"
#include "Bethesda/BSShaderPPLightingProperty.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiGeometry.hpp"

class BGSTerrainChunk
{
  public:
    BGSTerrainChunk();
    ~BGSTerrainChunk();
    
    enum ChunkTextureType : __int32
    {
      CHUNK_TEXTURE_DIFFUSE = 0x0,
      CHUNK_TEXTURE_NORMAL = 0x1,
    };

    BGSTerrainNode *pNode;
    NiPointer<NiGeometry> spMesh;
    NiPointer<NiGeometry> spWater;
    NiPointer<NiGeometry> spWaterAtReflectionHeight;
    NiPointer<BSMultiBoundNode> spNode;
    NiPointer<BSMultiBoundNode> spWaterNode;
    NiPointer<BSMultiBoundNode> spWaterReflNode;
    TESObjectREFR *pLODWaterRef;
    TESObjectREFR *pLODWaterAtReflectionHeightRef;
    NiPointer<BGSTerrainChunkLoadTask> spLoadTask;
    bool bDoneLoading;
    bool bAttached;
    bool bPrepared;
    NiPointer<BSShaderPPLightingProperty> spLightingProp;
};

static_assert(sizeof(BGSTerrainChunk) == 0x30, "BGSTerrainChunk has wrong size");
