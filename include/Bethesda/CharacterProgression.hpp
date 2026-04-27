#pragma once

namespace CommonLib {

  class CharacterProgressionData;

  class CharacterProgression
  {
    public:

      CharacterProgressionData *pData;
  };

  static_assert(sizeof(CharacterProgression) == 0x4, "CharacterProgression has wrong size");
  
} // namespace CommonLib
