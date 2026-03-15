#pragma once
#include <cstdint>

template <typename ENUM, typename STORAGE>
class hkEnum
{
  public:
    hkEnum();
    ~hkEnum();

    STORAGE m_storage;
};

static_assert(sizeof(hkEnum<void*, std::int32_t>) == 0x4, "hkEnum has wrong size");
