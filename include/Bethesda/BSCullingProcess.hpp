#pragma once
#include <cstdint>
#include "Gamebryo/NiCullingProcess.hpp"
#include "Bethesda/BSCompoundFrustum.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiAccumulator.hpp"

class BSCullingProcess : NiCullingProcess
{
  public:
    BSCullingProcess();
    ~BSCullingProcess();

    enum BSCPCullingType : std::int32_t
    {
      BSCP_CULL_NORMAL = 0x0,
      BSCP_CULL_ALLPASS = 0x1,
      BSCP_CULL_ALLFAIL = 0x2,
      BSCP_CULL_IGNOREMULTIBOUNDS = 0x3,
      BSCP_CULL_FORCEMULTIBOUNDSNOUPDATE = 0x4,
    };

    BSCullingProcess::BSCPCullingType kCullMode;
    BSCullingProcess::BSCPCullingType eTypeStackA[10];
    std::uint32_t iCTStackIndex;
    BSCompoundFrustum* pCompoundFrustum;
    NiPointer<NiAccumulator> spAccumulator;
};

static_assert(sizeof(BSCullingProcess) == 0xC8, "BSCullingProcess has wrong size");
