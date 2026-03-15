#pragma once
#include <cstdint>
#include "Bethesda/bhkSerializable.hpp"

class bhkWorldObject : public bhkSerializable
{
  public:
    bhkWorldObject();
    ~bhkWorldObject();

    std::uint32_t iFlags;
};

static_assert(sizeof(bhkWorldObject) == 0x14, "bhkWorldObject has wrong size");
