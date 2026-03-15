#pragma once
#include <cstdint>

class NiBinaryStream 
{
  public:
    NiBinaryStream();
    virtual ~NiBinaryStream();

    std::uint32_t m_uiAbsoluteCurrentPos;

    std::uint32_t (__cdecl *m_pfnRead)(NiBinaryStream *, void *, std::uint32_t, std::uint32_t *, std::uint32_t);
    std::uint32_t (__cdecl *m_pfnWrite)(NiBinaryStream *, const void *, std::uint32_t, std::uint32_t *, std::uint32_t);
};

static_assert(sizeof(NiBinaryStream) == 0x10, "NiBinaryStream has wrong size");
