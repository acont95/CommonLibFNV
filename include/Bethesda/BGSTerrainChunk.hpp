#pragma once
#include <cstdint>
#include "Bethesda/BGSTerrainChunkLoadTask.hpp"
#include "Bethesda/BSShaderPPLightingProperty.hpp"

class BGSTerrainNode;
class TESObjectREFR;
class BGSTerrainNode;
class BGSTerrainNode;

class BGSTerrainChunk
{
  public:
    BGSTerrainChunk();
    ~BGSTerrainChunk();
    
    enum ChunkTextureType : std::int32_t
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
