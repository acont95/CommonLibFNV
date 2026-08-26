#pragma once

namespace CommonLib  {

  class CombatTimer
  {
    public:
      float fStartTime;
      float fTargetTime;
  };

  static_assert(sizeof(CombatTimer) == 0x8, "CombatTimer  has wrong size");
  
} // namespace CommonLib
