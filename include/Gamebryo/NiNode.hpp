#pragma once
#include "Gamebryo/NiAVObject.hpp"
#include "Gamebryo/NiTObjectArray.hpp"

namespace CommonLib {

  class NiNode : public NiAVObject
  {
    public:
      NiNode();
      virtual ~NiNode();

      NiTObjectArray<NiPointer<NiAVObject>> m_kChildren;
  };

  static_assert(sizeof(NiNode) == 0xAC, "NiNode has wrong size");
  
} // namespace CommonLib
