#pragma once
#include "Gamebryo/NiObject.hpp"
#include "Gamebryo/NiPointer.hpp"

class Ni2DBuffer : NiObject
{
  public:
    Ni2DBuffer();
    virtual ~Ni2DBuffer();

    enum MultiSamplePreference : __int32
    {
      MULTISAMPLE_NONE = 0x0,
      MULTISAMPLE_2 = 0x1,
      MULTISAMPLE_4 = 0x2,
      MULTISAMPLE_8 = 0x3,
    };

    enum CopyFilterPreference : __int32
    {
      COPY_FILTER_NONE = 0x0,
      COPY_FILTER_POINT = 0x1,
      COPY_FILTER_LINEAR = 0x2,
      COPY_FILTER_MAX = 0x3,
    };

    const class RendererData
    {
      public:
        RendererData();
        virtual ~RendererData();
    };

    unsigned int m_uiWidth;
    unsigned int m_uiHeight;
    NiPointer<Ni2DBuffer::RendererData> m_spRendererData;
};

static_assert(sizeof(Ni2DBuffer) == 0x14, "Ni2DBuffer has wrong size");
