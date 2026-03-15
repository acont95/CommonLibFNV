#pragma once
#include <Windows.h>
#include <cstdint>

class NiCriticalSection
{
  public:
    NiCriticalSection();
    ~NiCriticalSection();

    CRITICAL_SECTION m_kCriticalSection;
    std::uint8_t pad01[104];
};

static_assert(sizeof(NiCriticalSection) == 0x80, "NiCriticalSection has wrong size");
