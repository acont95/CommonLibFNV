#pragma once
#include <cstdint>
#include "Havok/hkGeometry.hpp"

template <typename T>
class hkArrayBase
{
  public:
    hkArrayBase();
    ~hkArrayBase();

    T* m_data;
    std::int32_t m_size;
    std::int32_t m_capacityAndFlags;
};

static_assert(sizeof(hkArrayBase<void*>) == 0xC, "hkArrayBase has wrong size");
