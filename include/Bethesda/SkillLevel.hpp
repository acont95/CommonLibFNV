#pragma once
#include <cstdint>

namespace CommonLib {

  class SkillLevel
  {
    public:

      enum Value
      {
        NOVICE = 0x0,
        APPRENTICE = 0x1,
        JOURNEYMAN = 0x2,
        EXPERT = 0x3,
        MASTER = 0x4,
        SKILL_LEVEL_COUNT = 0x5,
      };
  };

  static_assert(sizeof(SkillLevel) == 0x1, "SkillLevel has wrong size");
  
} // namespace CommonLib
