#pragma once
#include <cstdint>
#include "Gamebryo/NiSkinData.hpp"

namespace CommonLib {

  class NiAVObject;

  class NiSkinInstance : public NiObject
  {
    public:

      NiPointer<NiSkinData> m_spSkinData;
      NiPointer<NiSkinPartition> m_spSkinPartition;
      NiAVObject* m_pkRootParent;
      NiAVObject** m_ppkBones;
      std::uint32_t m_uiFrameID;
      std::uint32_t m_uiNumMatrices;
      std::uint32_t m_uiNumRegisters;
      std::uint32_t m_uiAllocatedSize;
      void *m_pvBoneMatrices;
      void *m_pvPrevBoneMatrices;
      void *m_pvSkinToWorldWorldToSkinMatrix;
  };

  static_assert(sizeof(NiSkinInstance) == 0x34, "NiSkinInstance has wrong size");
  
} // namespace CommonLib
