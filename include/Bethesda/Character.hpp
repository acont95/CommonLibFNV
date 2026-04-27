#pragma once
#include "Bethesda/Actor.hpp"

namespace CommonLib {

  class BipedAnim;

  class Character : public Actor
  {
    public:
      virtual ~Character();

      BipedAnim *pBiped;
      float fArmorRating;
      float fArmorThreshold;
      bool bTrespassing;
      bool bGuard;
      float fequippedweight;
  };

  static_assert(sizeof(Character) == 0x1C8, "Character has wrong size");
  
} // namespace CommonLib
