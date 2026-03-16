#pragma once
#include <cstdint>
#include "Gamebryo/NiSkinPartition.hpp"
#include "Gamebryo/NiTransform.hpp"

class NiSkinData : public NiObject
{
  public:
    NiSkinData();
    ~NiSkinData();

    struct NiSkinData::BoneVertData
    {
      std::uint16_t m_usVert;
      float m_fWeight;
    };

    struct NiSkinData::BoneData
    {
      NiTransform m_kSkinToBone;
      NiBound m_kBound;
      NiSkinData::BoneVertData *m_pkBoneVertData;
      std::uint16_t m_usVerts;
    };

    NiPointer<NiSkinPartition> m_spSkinPartition;
    NiTransform m_kRootParentToSkin;
    NiSkinData::BoneData* m_pkBoneData;
    std::uint32_t m_uiBones;
};

static_assert(sizeof(NiSkinData) == 0x48, "NiSkinData has wrong size");
