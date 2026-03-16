#pragma once
#include "Gamebryo/NiPropertyState.hpp"
#include "Gamebryo/NiSkinInstance.hpp"
#include "Gamebryo/NiAVObject.hpp"

namespace CommonLib {

  class NiShader;

  class NiGeometry : public NiAVObject
  {
    public:
      NiGeometry();
      ~NiGeometry();

      NiPropertyState m_PropertyState;
      NiPointer<NiGeometryData> m_spModelData;
      NiPointer<NiSkinInstance> m_spSkinInstance;
      NiShader *m_spShader;
  };

  static_assert(sizeof(NiGeometry) == 0xC4, "NiGeometry has wrong size");
  
} // namespace CommonLib
