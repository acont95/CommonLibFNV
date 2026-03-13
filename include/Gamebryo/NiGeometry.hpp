#pragma once
#include "Gamebryo/NiPropertyState.hpp"
#include "Gamebryo/NiGeometryData.hpp"
#include "Gamebryo/NiSkinInstance.hpp"
#include "Gamebryo/NiShader.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiAVObject.hpp"

class NiGeometry : NiAVObject
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
