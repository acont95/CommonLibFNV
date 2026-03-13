#pragma once

template <typename T>
class NiTNewInterface
{
  public:
    NiTNewInterface();
    ~NiTNewInterface();
};

static_assert(sizeof(NiTNewInterface<unsigned int>) == 0x1, "NiTNewInterface has wrong size");
