#pragma once 
#include <cstdint>
#include "Gamebryo/NiBound.hpp"
#include "Gamebryo/NiAdditionalGeometryData.hpp"
#include "Gamebryo/NiPointer.hpp"

namespace CommonLib {

  class NiPoint3;
  class NiColorA;
  class NiPoint2;

  class NiGeometryData : public NiObject
  {
    public:
      NiGeometryData();
      ~NiGeometryData();

      class RendererData
      {
        public:
          RendererData();
          virtual ~RendererData();
      };


      std::uint16_t m_usVertices;
      std::uint16_t m_usID;
      std::uint16_t m_usDataFlags;
      std::uint16_t m_usDirtyFlags;
      NiBound m_kBound;
      NiPoint3 *m_pkVertex;
      NiPoint3 *m_pkNormal;
      NiColorA *m_pkColor;
      NiPoint2 *m_pkTexture;
      NiPointer<NiAdditionalGeometryData> m_spAdditionalGeomData;
      NiGeometryData::RendererData *m_pkBuffData;
      std::uint8_t m_ucKeepFlags;
      std::uint8_t m_ucCompressFlags;
      bool m_bVBLocked;
      bool m_bVBLockWrite;
      bool m_bSaveVertexData;
  };

  static_assert(sizeof(NiGeometryData) == 0x40, "NiGeometryData has wrong size");
  
} // namespace CommonLib
