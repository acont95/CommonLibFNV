#pragma once
#include <cstdint>
#include "Bethesda/MagicLight.hpp"

class MagicCaster
{
  public:
    MagicCaster();
    virtual ~MagicCaster();

    enum State : std::int32_t
    {
      NO_SPELL = 0x0,
      AIM = 0x1,
      CAST = 0x2,
      RELEASE = 0x3,
      FIND_TARGETS = 0x4,
      ERR_SPELL_DISABLED = 0x5,
      ERR_ALREADY_CASTING = 0x6,
      ERR_CANNOT_CAST = 0x7,
    };


    MagicLight *pLight;
    MagicCaster::State eState;
};

static_assert(sizeof(MagicCaster) == 0xC, "MagicCaster has wrong size");
