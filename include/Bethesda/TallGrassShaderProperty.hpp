#pragma once
#include <cstdint>
#include <cstdint>
#include "Bethesda/BSStringT.hpp"
#include "Bethesda/TallGrassGroup.hpp"
#include "Bethesda/GrassLoadTask.hpp"
#include "Bethesda/BSShaderLightingProperty.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiAVObject.hpp"
#include "Gamebryo/NiTexture.hpp"
#include "Gamebryo/NiRefObject.hpp"
#include "Gamebryo/NiTriBasedGeomData.hpp"
#include "Gamebryo/NiTexturingProperty.hpp"
#include "Gamebryo/NiAlphaProperty.hpp"
#include "Gamebryo/NiStencilProperty.hpp"


class TallGrassShaderProperty : public BSShaderLightingProperty
{
  public:
    TallGrassShaderProperty();
    ~TallGrassShaderProperty();

    enum TerrainGeometrySection : std::int32_t
    {
      TGSP_NONE = 0x0,
      TGSP_UPPERLEFT = 0x1,
      TGSP_LOWERLEFT = 0x2,
      TGSP_LOWERRIGHT = 0x3,
      TGSP_UPPERRIGHT = 0x4,
    };

    struct GrassParam
    {
      const char* pcGeomFilename;
      unsigned int iGrassID;
      float fPositionRange;
      float fHeightRange;
      float fColorRange;
      float fWaveOffsetRange;
      float fWavePeriod;
      bool bVertexLighting;
      bool bUniformScaing;
      bool bFitToSlope;
      bool bWind;
    };

    class CachedGeometry : public NiRefObject
    {
      public:
        NiPointer<NiTriBasedGeomData> spTriGeomData;
        float *pInstanceIndex;
        int iVertices;
        NiPointer<NiTexture> spBaseTexture;
        NiPointer<NiAlphaProperty> spAlphaBlend;
        NiPointer<NiAlphaProperty> spAlphaNoBlend;
        NiPointer<NiStencilProperty> spStencil;
        NiPointer<GrassLoadTask> spGrassLoadTask;
        float fBoundRadius;
        int iMaxInstanceCount;
        bool bTristrip;
        bool bBillboard;
        bool bQueued;
        std::uint16_t usInstanceTriCount;
    };

    TallGrassGroup* pGrassGroup;
    NiPointer<NiAVObject> spTerrainChunk;
    NiPointer<NiTexture> spBaseTexture;
    BSStringT<char> TextureFilename;
    NiTexturingProperty::ClampMode TextureClampMode;
    TallGrassShaderProperty::GrassParam* pGrassParam;
};

static_assert(sizeof(TallGrassShaderProperty) == 0x98, "TallGrassShaderProperty has wrong size");
