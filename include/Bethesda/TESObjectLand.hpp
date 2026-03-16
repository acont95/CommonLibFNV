#pragma once
#include <cstdint>
#include "Bethesda/TESLandTexture.hpp"
#include "Bethesda/QueuedFile.hpp"
#include "Bethesda/bhkRigidBody.hpp"
#include "Bethesda/TESChildCell.hpp"
#include "Gamebryo/NiLines.hpp"
#include "Gamebryo/NiTPointerMap.hpp"
#include "Gamebryo/NiPoint2.hpp"

class TESObjectCELL;
class TESGrassAreaParam;
class NiColorA;
class hkpMoppCode;

class TESObjectLAND : public TESForm, public TESChildCell
{
  public:
    TESObjectLAND();
    ~TESObjectLAND();

    struct LoadedLandData
    {
      NiNode** ppMesh;
      NiPoint3** ppVertices;
      NiPoint3** ppNormals;
      NiColorA** ppColorsA;
      bool** ppNormalsSet;
      NiPointer<NiLines> spBorder;
      NiPoint2 HeightExtents;
      TESLandTexture* pDefQuadTexture[4];
      TESLandTexture** pQuadTextureArray[4];
      float** ppPercentArrays[4];
      hkpMoppCode* pMoppCode;
      NiTPointerMap<std::uint32_t, TESGrassAreaParam**> pmGrassMap[4];
      NiPointer<bhkRigidBody> spLandRB;
      std::int32_t iCellX;
      std::int32_t iCellY;
      float fBaseHeight;
    };

    struct OBJ_LAND
    {
      std::uint32_t iFlags;
    };

    OBJ_LAND Data;
    TESObjectCELL* pParentCell;
    NiPointer<QueuedFile> spQueuedTextures;
    LoadedLandData *pLoadedData;
};

static_assert(sizeof(TESObjectLAND) == 0x2C, "TESObjectLAND has wrong size");
