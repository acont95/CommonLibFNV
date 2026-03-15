#pragma once
#include <cstdint>

class BSExtraData 
{
  public:
    BSExtraData();
    virtual ~BSExtraData();

    std::uint8_t cEtype;
    BSExtraData* pNext;
};

static_assert(sizeof(BSExtraData) == 0xC, "BSExtraData has wrong size");
