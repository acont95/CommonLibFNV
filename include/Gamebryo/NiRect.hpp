#pragma once

template <typename T>
class NiRect
{
  public:
    NiRect();
    ~NiRect();

    T m_left;
    T m_right;
    T m_top;
    T m_bottom;
};

static_assert(sizeof(NiRect<float>) == 0x10, "NiRect has wrong size");
