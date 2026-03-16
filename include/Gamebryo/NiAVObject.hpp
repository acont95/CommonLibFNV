#pragma once
#include <cstdint>
#include "Gamebryo/NiTPointerList.hpp"
#include "Gamebryo/NiCollisionObject.hpp"
#include "Gamebryo/NiProperty.hpp"
#include "Gamebryo/NiTransform.hpp"

namespace CommonLib {

  class NiNode;
  class BSNiBound;

  class NiAVObject : public NiObjectNET {
    public:
      NiAVObject();
      virtual ~NiAVObject();

      NiNode* m_pkParent;
      NiPointer<NiCollisionObject> m_spCollisionObject;
      BSNiBound* m_kWorldBound;
      NiTPointerList<NiPointer<NiProperty>> m_kPropertyList;
      std::uint32_t m_uFlags;
      NiTransform m_kLocal;
      NiTransform m_kWorld;
  };

  static_assert(sizeof(NiAVObject) == 0x9C, "NiAVObject has wrong size");

} // namespace CommonLib
