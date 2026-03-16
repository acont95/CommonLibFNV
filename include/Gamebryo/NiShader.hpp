#pragma once
#include <cstdint>
#include "Gamebryo/NiRefObject.hpp"
#include "Gamebryo/NiFixedString.hpp"

class NiShader : public NiRefObject
{
  public:
    NiShader();
    ~NiShader();

    NiFixedString m_kName;
    std::uint32_t m_uiImplementation;
    bool m_bInitialized;
};

static_assert(sizeof(NiShader) == 0x14, "NiShader has wrong size");
