#pragma once
#include <cstdint>
#include "Gamebryo/NiObject.hpp"
#include "Gamebryo/NiTPrimitiveArray.hpp"

namespace CommonLib {

  class NiAdditionalGeometryData : public NiObject
  {
    public:

      struct NiAGDDataStream
      {
        std::uint8_t m_uFlags;
        std::uint32_t m_uiType;
        std::uint32_t m_uiUnitSize;
        std::uint32_t m_uiTotalSize;
        std::uint32_t m_uiStride;
        std::uint32_t m_uiBlockIndex;
        std::uint32_t m_uiBlockOffset;
      };

      class NiAGDDataBlock
      {
        public:
          NiAGDDataBlock();
          virtual ~NiAGDDataBlock();
          std::uint32_t m_uiDataBlockSize;
          std::uint8_t *m_pucDataBlock;
          bool m_bOwnData;
          bool m_bBSHeap;
      };

      std::uint32_t m_uiRevID;
      std::uint16_t m_usVertexCount;
      std::uint32_t m_uiDataStreamCount;
      NiAdditionalGeometryData::NiAGDDataStream *m_pkDataStreamEntries;
      std::uint32_t m_uiD3DStream;
      NiTPrimitiveArray<NiAdditionalGeometryData::NiAGDDataBlock *> m_aDataBlocks;
  };

  static_assert(sizeof(NiAdditionalGeometryData) == 0x2C, "NiAdditionalGeometryData has wrong size");
  
} // namespace CommonLib
