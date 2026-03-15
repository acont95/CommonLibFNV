#pragma once
#include <cstdint>
#include "Gamebryo/NiNode.hpp"

template <typename T, std::uint32_t N>
class BSSimpleArray
{
  public:
    BSSimpleArray();
    virtual ~BSSimpleArray();

    T* pBuffer;
    std::uint32_t iSize;
    std::uint32_t iReservedSize;
};

static_assert(sizeof(BSSimpleArray<void*, 1024>) == 0x10);
