#pragma once
#include "Types.hpp"
#include "Bethesda/ShadowSceneLight.hpp"
#include "Gamebryo/NiGeometry.hpp"
#include "Gamebryo/NiTObjectArray.hpp"
#include "Gamebryo/NiShadeProperty.hpp"

class BSShaderProperty : public NiShadeProperty
{
  public:
    BSShaderProperty();
    virtual ~BSShaderProperty();

    enum TextureTypeEnum : __int32
    {
      TEXTYPE_DIFFUSE = 0x0,
      TEXTYPE_GLOSS = 0x1,
      TEXTYPE_SKIN_SST = 0x2,
      TEXTYPE_HAIR_LAYER = 0x2,
    };

    enum etAccumulationHint : __int32
    {
      BSSP_HINT_NORMAL = 0x0,
      BSSP_HINT_SORT = 0x1,
      BSSP_HINT_GROUP_IMMEDIATE = 0x2,
      BSSP_HINT_GROUP_NODEPTH = 0x3,
      BSSP_HINT_GROUP_DECAL = 0x4,
      BSSP_HINT_GROUP_DYNAMIC_DECAL = 0x5,
      BSSP_HINT_GROUP_REFRACT = 0x6,
      BSSP_HINT_GROUP_1STPERSONNOREFRACT = 0x7,
      BSSP_HINT_GROUP_VOLUMETRICFOG = 0x8,
      BSSP_HINT_GROUP_MORPH = 0x9,
      BSSP_HINT_GROUP_LOD = 0xA,
      BSSP_HINT_GROUP_LODTREE = 0xB,
      BSSP_HINT_GROUP_LODBILLBOARD = 0xC,
      BSSP_HINT_GROUP_VELOCITY = 0xD,
      BSSP_HINT_GROUP_FADING = 0xE,
    };

    enum EShaderPropertyFlag : __int32
    {
      BSSP_SPECULAR = 0x0,
      BSSP_SKINNED = 0x1,
      BSSP_LOWDETAIL = 0x2,
      BSSP_VERTEX_ALPHA = 0x3,
      BSSP_MOTION_BLUR = 0x4,
      BSSP_SINGLEPASS = 0x5,
      BSSP_FALLOFF = 0x6,
      BSSP_ENVMAP = 0x7,
      BSSP_ALPHATEX = 0x8,
      BSSP_ZPREPASS = 0x9,
      BSSP_FLAG_FACEGENBLEND = 0xA,
      BSSP_FLAG_PARALLAX = 0xB,
      BSSP_FLAG_MODELSPACENORMALS = 0xC,
      BSSP_FLAG_NOPROJSHADOW = 0xD,
      BSSP_FLAG_LANDSCAPE = 0xE,
      BSSP_FLAG_REFRACTION = 0xF,
      BSSP_FLAG_REFRACTION_FIRE = 0x10,
      BSSP_FLAG_EYEREFLECT = 0x11,
      BSSP_FLAG_HAIR = 0x12,
      BSSP_FLAG_DYNAMICALPHA = 0x13,
      BSSP_FLAG_LOCALMAP_CLEAR = 0x14,
      BSSP_FLAG_WINDOWREFLECT = 0x15,
      BSSP_FLAG_BILLBOARDTREE = 0x16,
      BSSP_FLAG_SHADOWFRUSTUM = 0x17,
      BSSP_FLAG_MULTIPLE_TEXTURES = 0x18,
      BSSP_FLAG_REMAP_TEXTURES = 0x19,
      BSSP_FLAG_DECAL = 0x1A,
      BSSP_FLAG_DYNAMIC_DECAL = 0x1B,
      BSSP_FLAG_PARALLAXOCCLUSION = 0x1C,
      BSSP_FLAG_EXTERNAL_EMITTANCE = 0x1D,
      BSSP_FLAG_SHADOWMAP = 0x1E,
      BSSP_FLAG_ZBUFFER_TEST = 0x1F,
      BSSP_FLAG_ZBUFFER_WRITE = 0x20,
      BSSP_FLAG_LODLANDSCAPE = 0x21,
      BSSP_FLAG_LODBUILDING = 0x22,
      BSSP_FLAG_NOFADE = 0x23,
      BSSP_FLAG_REFRACTION_TINT = 0x24,
      BSSP_FLAG_VERTEXCOLORS = 0x25,
      BSSP_1ST_PERSON = 0x26,
      HSP_FLAG_PTFIRST = 0x27,
      HSP_FLAG_2NDLIGHT = 0x28,
      HSP_FLAG_3RDLIGHT = 0x29,
      TGSP_FLAG_VERTEX_LIGHTING = 0x2A,
      TGSP_FLAG_UNIFORM_SCALE = 0x2B,
      TGSP_FLAG_FIT_SLOPE = 0x2C,
      TGSP_FLAG_BILLBOARD = 0x2D,
      BSSP_FLAG_SKIP_LANDLO_PASS = 0x2E,
      BSSP_FLAG_ENVMAP_LIGHTFADE = 0x2F,
      BSSP_FLAG_WIREFRAME = 0x30,
      BSSP_FLAG_VATS_SELECTION = 0x31,
      BSSP_FLAG_SHOW_IN_LOCAL_MAP = 0x32,
      BSSP_FLAG_PREMULT_ALPHA = 0x33,
      BSSP_FLAG_SKIP_NORMAL_MAPS = 0x34,
      BSSP_FLAG_ALPHA_DECAL = 0x35,
      BSSP_FLAG_NO_TRANSPARENCY_MULTISAMPLING = 0x36,
      BSSP_FLAG_STINGER = 0x37,
      BSSP_FLAG_COUNT = 0x38,
    };

    class RenderPass
    {
      public:
        RenderPass();
        ~RenderPass();

        NiGeometry *pGeometry;
        unsigned __int16 usPassEnum;
        unsigned __int8 eAccumulationHint;
        bool bFirstPass;
        bool bLastPass;
        unsigned __int8 ucNumLights;
        unsigned __int8 ucMaxNumLights;
        unsigned __int8 ucExtraParam;
        ShadowSceneLight **ppSceneLights;
    };

    class RenderPassArray
    {
      public:
        RenderPassArray();
        ~RenderPassArray();

        NiTObjectArray<RenderPass*> pPassA;
        unsigned int iSize;
    };

    class PreviousTransform
    {
      D3DXMATRIX matWorld;
      float *pfBones;
      float *pfCurrentBones;
      D3DXMATRIX matWorldView;
      D3DXMATRIX matWorldViewProj;
      D3DXMATRIX matWorldViewT;
      D3DXMATRIX matWorldViewProjT;
      bool bBonesReady;
      bool bWorldReady;
      unsigned __int16 usWorldViewCounter;
      unsigned __int16 usWorldViewProjCounter;
      unsigned __int16 usBoneCounter;
    };

    unsigned int ulFlags[2];
    float fAlpha;
    float fFadeAlpha;
    float fEnvmapScale;
    float fCameraDistance;
    int iLastRenderPassState;
    RenderPassArray* pRenderPassList;
    RenderPassArray* pDepthMapRenderPassList;
    RenderPassArray* pConstAlphaRenderPassList;
    RenderPassArray* pLocalMapRenderPassList;
    RenderPassArray* pSIBlockRenderPassList;
    RenderPassArray* pWaterFogRenderPassList;
    RenderPassArray* pSilhouettePassList;
    int iShader;
    float fDepthBias;
};

static_assert(sizeof(BSShaderProperty) == 0x60);
