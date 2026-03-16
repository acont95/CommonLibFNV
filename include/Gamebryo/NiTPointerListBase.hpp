#pragma once
#include <cstdint>
#include "Gamebryo/NiTListBase.hpp"
#include "Gamebryo/NiTPointerAllocator.hpp"

template <class TAllocator, typename T>
class NiTPointerListBase : public NiTListBase<TAllocator, T>
{
  public:
    NiTPointerListBase();
    ~NiTPointerListBase();
};

static_assert(sizeof(NiTPointerListBase<NiTPointerAllocator<std::uint32_t>, void*>) == 0xC, "NiTPointerListBase has wrong size");
