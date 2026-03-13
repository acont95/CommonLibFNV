#pragma once
#include <cstdint>
#include "Gamebryo/NiObject.hpp"
#include "Gamebryo/NiGeometryData.hpp"

class NiSkinPartition : NiObject
{
  public:
    NiSkinPartition();
    ~NiSkinPartition();

    class Partition
    {
      public:
        Partition();
        virtual ~Partition();
        std::uint16_t *m_pusBones;
        float *m_pfWeights;
        std::uint16_t *m_pusVertexMap;
        std::uint8_t *m_pucBonePalette;
        std::uint16_t *m_pusTriList;
        std::uint16_t *m_pusStripLengths;
        std::uint16_t m_usVertices;
        std::uint16_t m_usTriangles;
        std::uint16_t m_usBones;
        std::uint16_t m_usStrips;
        std::uint16_t m_usBonesPerVertex;
        NiGeometryData::RendererData *m_pkBuffData;
    };

    std::uint32_t m_uiPartitions;
    NiSkinPartition::Partition *m_pkPartitions;
};

static_assert(sizeof(NiSkinPartition) == 0x10, "NiSkinPartition has wrong size");
