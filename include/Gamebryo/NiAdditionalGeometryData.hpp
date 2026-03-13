#pragma once
#include <cstdint>
#include "Gamebryo/NiObject.hpp"
#include "Gamebryo/NiTPrimitiveArray.hpp"

class NiAdditionalGeometryData : NiObject
{
  public:
    NiAdditionalGeometryData();
    ~NiAdditionalGeometryData();

    struct NiAGDDataStream
    {
      unsigned __int8 m_uFlags;
      unsigned int m_uiType;
      unsigned int m_uiUnitSize;
      unsigned int m_uiTotalSize;
      unsigned int m_uiStride;
      unsigned int m_uiBlockIndex;
      unsigned int m_uiBlockOffset;
    };

    class NiAGDDataBlock
    {
      public:
        NiAGDDataBlock();
        virtual ~NiAGDDataBlock();
        unsigned int m_uiDataBlockSize;
        unsigned __int8 *m_pucDataBlock;
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
