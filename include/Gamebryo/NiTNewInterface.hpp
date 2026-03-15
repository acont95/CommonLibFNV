#pragma once
#include <cstdint>

template <typename T>
class NiTNewInterface
{
  public:
    NiTNewInterface();
    ~NiTNewInterface();
};

static_assert(sizeof(NiTNewInterface<std::uint32_t>) == 0x1, "NiTNewInterface has wrong size");
