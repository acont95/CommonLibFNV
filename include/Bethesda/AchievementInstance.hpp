#pragma once
#include <cstdint>

namespace CommonLib {

  class AchievementInstance
  {
    public:
      AchievementInstance();
      ~AchievementInstance();

      bool bUnlocked;
      std::int32_t iCurrentValue;
      bool bTracking;
  };

  static_assert(sizeof(AchievementInstance) == 0xC, "AchievementInstance has wrong size");
  
} // namespace CommonLib
