#pragma once

class NiPoint2
{
  public:
    NiPoint2();
    ~NiPoint2();

    float x;
    float y;
};

static_assert(sizeof(NiPoint2) == 0x8, "NiPoint2 has wrong size");
