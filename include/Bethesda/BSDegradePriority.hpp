#pragma once
#include <cstdint>

class BSDegradePriority
{
  public:
    BSDegradePriority();
    ~BSDegradePriority();

    std::uint8_t cPriorityL;
    std::uint8_t cPriorityH;
    std::uint8_t cPriorityC;
    std::uint8_t cState;
};

static_assert(sizeof(BSDegradePriority) == 0x4, "BSDegradePriority has wrong size");