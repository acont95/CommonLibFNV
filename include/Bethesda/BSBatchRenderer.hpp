#pragma once
#include <cstdint>
#include "Bethesda/BSTPersistentList.hpp"
#include "Bethesda/BSShaderProperty.hpp"
#include "Bethesda/BSSimpleList.hpp"
#include "Gamebryo/NiObject.hpp"
#include "Gamebryo/NiTMap.hpp"
#include "Gamebryo/NiTPointerList.hpp"

namespace CommonLib {

  class BSBatchRenderer : public NiObject
  {
    public:
      BSBatchRenderer();
      virtual ~BSBatchRenderer();

      enum RENDERPASS_BUCKET_TYPE
      {
        RBT_STANDARD = 0x0,
        RBT_TWO_SIDED_LIGHTING = 0x1,
        RBT_TWO_SIDED_LIGHTING_ALPHA_TEST = 0x2,
        RBT_ALPHA_TEST = 0x3,
        RBT_ALPHA_TEST_NO_TRANSPARENCY_MULTISAMPLING = 0x4,
        RBT_COUNT = 0x5,
      };

      enum eStateUpdateFlag
      {
        BSBR_NONE = 0x0,
        BSBR_PASSCONSTANTS = 0x1,
        BSBR_PASSTRANSFORM = 0x2,
        BSBR_PASSSTATES = 0x4,
        BSBR_PASSTEXTURES = 0x8,
        BSBR_SHADERCONSTANTS = 0x10,
        BSBR_SHADERTRANSFORM = 0x20,
        BSBR_SHADERSTATES = 0x40,
        BSBR_SHADERTEXTURES = 0x80,
        BSBR_SHADER = 0x100,
        BSBR_ALL = 0xFFFF,
      };

      enum GEOMETRY_GROUP_ENUM
      {
        GG_LOD = 0x0,
        GG_NO_DEPTH = 0x1,
        GG_STATIC_DECAL = 0x2,
        GG_DYNAMIC_DECAL = 0x3,
        GG_STATIC_DECAL_WIREFRAME = 0x4,
        GG_DYNAMIC_DECAL_WIREFRAME = 0x5,
        GG_REFRACTIVE = 0x6,
        GG_VELOCITY = 0x7,
        GG_1ST_PERSON_NONREFRACTIVE = 0x8,
        GG_FADING = 0x9,
        GG_IMMEDIATE = 0xA,
        GG_RENDER_DEPTH = 0xB,
        GG_RENDER_DEPTH_1STPERSON = 0xC,
        GG_COUNT = 0xD,
      };


      class PassGroup
      {
        public:

          BSTPersistentList<NiTPointerAllocator<std::uint32_t>,BSShaderProperty::RenderPass *> pListA[5];
          std::int32_t iSize;
      };

      class GeometryGroup
      {
        public:

          enum etFlags
          {
            BSSA_GEOMETRYGROUPFLAG_NOSORT = 0x0,
          };

          std::uint8_t ucFlags;
          std::uint16_t usCount;
          std::uint32_t uiPassCount;
          BSBatchRenderer *pBatchRenderer;
          BSTPersistentList<NiTPointerAllocator<std::uint32_t>,BSShaderProperty::RenderPass *> PassList;
          float fDepth;
      };

      BSBatchRenderer::PassGroup *pRenderPassA;
      NiTMap<std::uint32_t,std::uint32_t> RenderPassMap;
      std::uint32_t uiRenderPassCount;
      std::uint32_t uiCurrentFirstPass;
      std::uint32_t uiCurrentLastPass;
      struct BSInstanceRendering *pInstanceRenderer;
      BSSimpleList<unsigned short> kActivePassIndexList;
      std::int32_t iGroupingAlphas;
      bool bAlphaGroupZPrePass;
      BSBatchRenderer::GeometryGroup *pGeometryGroupsA[13];
      BSBatchRenderer::GeometryGroup *pAlphaGroupA[2];
      NiTPointerList<BSBatchRenderer::GeometryGroup *> AlphaGroupList[2];
      BSBatchRenderer::GeometryGroup *pCurrentAlphaGroup[2];
  };

  static_assert(sizeof(BSBatchRenderer) == 0x98, "BSBatchRenderer has wrong size");
  
} // namespace CommonLib
