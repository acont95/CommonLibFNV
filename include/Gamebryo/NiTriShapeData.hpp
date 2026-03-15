#pragma once
#include "Gamebryo/NiTriBasedGeomData.hpp"

class NiTriShapeData : NiTriBasedGeomData
{
  public:
    NiTriShapeData();
    virtual ~NiTriShapeData();

    class SharedNormalArray
    {
      unsigned __int16 m_usNumSharedNormals;
      unsigned __int16 *m_pusSharedNormalIndexArray;
    };

    class SNAMemBlock
    {
      unsigned __int16 *m_pusBlock;
      unsigned __int16 *m_pusFreeBlock;
      unsigned int m_uiBlockSize;
      unsigned int m_uiFreeBlockSize;
      SNAMemBlock *m_pkNext;
    };

    unsigned int m_uiTriListLength;
    unsigned __int16 *m_pusTriList;
    SharedNormalArray *m_pkSharedNormals;
    unsigned __int16 m_usSharedNormalsArraySize;
    SNAMemBlock *m_pkSNAMemoryBlocks;
};

static_assert(sizeof(NiTriShapeData) == 0x58, "NiTextureTransform has wrong size");
