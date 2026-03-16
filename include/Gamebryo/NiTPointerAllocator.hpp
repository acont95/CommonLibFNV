#pragma once
#include <cstdint>
#include "Gamebryo/NiTAbstractPoolAllocator.hpp"

template <typename T>
class NiTPointerAllocator : public NiTAbstractPoolAllocator<T>
{
  public:
    NiTPointerAllocator();
    ~NiTPointerAllocator();
};

static_assert(sizeof(NiTPointerAllocator<std::uint32_t>) == 0x1, "NiTPointerAllocator has wrong size");
