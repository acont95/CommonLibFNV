#pragma once
#include <cstdint>

namespace CommonLib {

  class NiAnimationKey
  {
    public:

      enum KeyContent
      {
        FLOATKEY = 0x0,
        POSKEY = 0x1,
        ROTKEY = 0x2,
        COLORKEY = 0x3,
        TEXTKEY = 0x4,
        BOOLKEY = 0x5,
        NUMKEYCONTENTS = 0x6,
      };

      enum KeyType
      {
        NOINTERP = 0x0,
        LINKEY = 0x1,
        BEZKEY = 0x2,
        TCBKEY = 0x3,
        EULERKEY = 0x4,
        STEPKEY = 0x5,
        NUMKEYTYPES = 0x6,
      };

      float m_fTime;
  };

  static_assert(sizeof(NiAnimationKey) == 0x4, "NiAnimationKey has wrong size");
  
} // namespace CommonLib
