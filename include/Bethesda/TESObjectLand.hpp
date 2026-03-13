#pragma once
#include "Bethesda/TESForm.hpp"
#include "Bethesda/TESObjectCell.hpp"
#include "Gamebryo/NiPointer.hpp"

class TESObjectLAND : TESForm, TESChildCell
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
      NiTPointerMap<unsigned int, TESGrassAreaParam**> pmGrassMap[4];
      NiPointer<bhkRigidBody> spLandRB;
      int iCellX;
      int iCellY;
      float fBaseHeight;
    };

    struct OBJ_LAND
    {
      unsigned int iFlags;
    };

    OBJ_LAND Data;
    TESObjectCell* pParentCell;
    NiPointer<QueuedFile> spQueuedTextures;
    LoadedLandData *pLoadedData;
};

static_assert(sizeof(TESObjectLand) == 0x2C, "TESObjectLand has wrong size");
