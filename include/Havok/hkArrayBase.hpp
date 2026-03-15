#pragma once
#include "Havok/hkGeometry.hpp"

template <typename T>
class hkArrayBase
{
  public:
    hkArrayBase();
    ~hkArrayBase();

    T* m_data;
    int m_size;
    int m_capacityAndFlags;
};

static_assert(sizeof(hkArrayBase<void*>) == 0xC, "hkArrayBase has wrong size");
