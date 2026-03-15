#pragma once
#include <cstdint>
#include "Gamebryo/NiTriBasedGeomData.hpp"

class NiTriShapeData : NiTriBasedGeomData
{
  public:
    NiTriShapeData();
    virtual ~NiTriShapeData();

    class SharedNormalArray
    {
      std::uint16_t m_usNumSharedNormals;
      std::uint16_t *m_pusSharedNormalIndexArray;
    };

    class SNAMemBlock
    {
      std::uint16_t *m_pusBlock;
      std::uint16_t *m_pusFreeBlock;
      unsigned int m_uiBlockSize;
      unsigned int m_uiFreeBlockSize;
      SNAMemBlock *m_pkNext;
    };

    unsigned int m_uiTriListLength;
    std::uint16_t *m_pusTriList;
    SharedNormalArray *m_pkSharedNormals;
    std::uint16_t m_usSharedNormalsArraySize;
    SNAMemBlock *m_pkSNAMemoryBlocks;
};

static_assert(sizeof(NiTriShapeData) == 0x58, "NiTextureTransform has wrong size");
