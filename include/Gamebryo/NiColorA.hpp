#pragma once

class NiColorA
{
  public:
    NiColorA();
    ~NiColorA();

    float r;
    float g;
    float b;
    float a;
};

static_assert(sizeof(NiColorA) == 0x10, "NiColorA has wrong size");
