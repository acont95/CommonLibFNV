#pragma once
#include <cstdint>
#include "Gamebryo/NiTPrimitiveArray.hpp"
#include "Gamebryo/NiProperty.hpp"
#include "Gamebryo/NiTexture.hpp"

namespace CommonLib {

  class NiTextureTransform;

  class NiTexturingProperty : public NiProperty
  {
    public:

      enum ClampMode
      {
        CLAMP_S_CLAMP_T = 0x0,
        CLAMP_S_WRAP_T = 0x1,
        WRAP_S_CLAMP_T = 0x2,
        WRAP_S_WRAP_T = 0x3,
        CLAMP_MAX_MODES = 0x4,
      };

      enum FilterMode
      {
        FILTER_NEAREST = 0x0,
        FILTER_BILERP = 0x1,
        FILTER_TRILERP = 0x2,
        FILTER_NEAREST_MIPNEAREST = 0x3,
        FILTER_NEAREST_MIPLERP = 0x4,
        FILTER_BILERP_MIPNEAREST = 0x5,
        FILTER_ANISO = 0x6,
        FILTER_MAGLERP_MINANISO = 0x7,
        FILTER_MAX_MODES = 0x8,
      };

      enum ApplyMode
      {
        APPLY_DECAL = 0x1,
        APPLY_DEPRECATED = 0x3,
        APPLY_DEPRECATED2 = 0x4,
        APPLY_MAX_MODES = 0x5,
      };

      enum MapClassID
      {
        MAP_CLASS_BASE = 0x0,
        MAP_CLASS_BUMP = 0x1,
        MAP_CLASS_PARALLAX = 0x2,
        MAP_CLASS_SHADER = 0x3,
        MAP_CLASS_MAX = 0x4,
      };

      enum MapEnum
      {
        BASE_INDEX = 0x0,
        DARK_INDEX = 0x1,
        DETAIL_INDEX = 0x2,
        GLOSS_INDEX = 0x3,
        GLOW_INDEX = 0x4,
        BUMP_INDEX = 0x5,
        PARALLAX_INDEX = 0x7,
        DECAL_BASE = 0x8,
        SHADER_BASE = 0x9,
        INDEX_MAX = 0xA,
      };

      enum UnnamedTextureMask
      {
        MULTITEXTURE_MASK = 0x1,
        DECALCOUNT_MASK = 0xFF0,
        DECALCOUNT_POS = 0x4,
      };

      class Map
      {
        public:
          Map();
          virtual ~Map();

          enum UnnamedCoordMask
          {
            TEXCOORD_MASK = 0xFF,
            TEXCOORD_POS = 0x0,
            FILTERMODE_MASK = 0xF00,
            FILTERMODE_POS = 0x8,
            CLAMPMODE_MASK = 0x3000,
            CLAMPMODE_POS = 0xC,
          };


          std::uint16_t m_uFlags;
          NiPointer<NiTexture> m_spTexture;
          NiTextureTransform* m_pkTextureTransform;
      };

      class ShaderMap : Map
      {
        public:
          ShaderMap();
          virtual ~ShaderMap();

          std::uint32_t m_uiID;
      };

      std::uint16_t m_uFlags;
      NiTPrimitiveArray<Map*> m_kMaps;
      NiTPrimitiveArray<ShaderMap*>* m_pkShaderMaps;
  };

  static_assert(sizeof(NiTexturingProperty) == 0x30, "NiTexturingProperty has wrong size");
  
} // namespace CommonLib
