#pragma once
#include <cstdint>

class BSHash 
{
  public:
    BSHash();
    ~BSHash();

    std::uint8_t cLast;
    std::uint8_t cLast2;
    std::uint8_t cLength;
    std::uint8_t cFirst;
    std::uint32_t iCRC;
};

static_assert(sizeof(BSHash) == 0x8, "BSHash has wrong size");
