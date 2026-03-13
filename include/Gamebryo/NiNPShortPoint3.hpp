#pragma once
#include <cstdint>

class NiNPShortPoint3
{
  public:
    NiNPShortPoint3();
    ~NiNPShortPoint3();

    std::int16_t x;
    std::int16_t y;
    std::int16_t z;
};

static_assert(sizeof(NiNPShortPoint3) == 0x6, "NiNPShortPoint3 has wrong size");
