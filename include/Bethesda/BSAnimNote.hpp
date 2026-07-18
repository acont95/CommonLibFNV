#pragma once
#include "Gamebryo/NiObject.hpp"

namespace CommonLib {

  class BSAnimNote : public NiObject
  {
    public:
      virtual ~BSAnimNote();

      enum AnimNoteType
      {
        BS_ANT_INVALID = 0x0,
        BS_ANT_GRABIK = 0x1,
        BS_ANT_LOOKIK = 0x2,
      };


      BSAnimNote::AnimNoteType eType;
      float fTime;
  };

  static_assert(sizeof(BSAnimNote) == 0x10, "BSAnimNote has wrong size");
  
} // namespace CommonLib
