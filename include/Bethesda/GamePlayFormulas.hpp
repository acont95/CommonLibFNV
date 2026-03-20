#pragma once

namespace CommonLib {

  class GamePlayFormulas
  {
    public:
      GamePlayFormulas();
      ~GamePlayFormulas();

      enum DifficultyLevel
      {
        DIFFICULTY_VERY_EASY = 0x0,
        DIFFICULTY_LOW = 0x0,
        DIFFICULTY_EASY = 0x1,
        DIFFICULTY_NORMAL = 0x2,
        DIFFICULTY_HARD = 0x3,
        DIFFICULTY_VERY_HARD = 0x4,
        DIFFICULTY_HIGH = 0x4,
      };

      enum HardcoreSetting 
      {
        HARDCORE_OFF = 0x0,
        HARDCORE_ON = 0x1,
      };
  };

  static_assert(sizeof(GamePlayFormulas) == 0x1, "GamePlayFormulas has wrong size");
  
} // namespace CommonLib
