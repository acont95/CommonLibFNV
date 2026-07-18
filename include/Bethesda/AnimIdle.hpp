#pragma once

#include "Gamebryo/NiRefObject.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Bethesda/KFModel.hpp"
#include "Bethesda/Animation.hpp"

namespace CommonLib {

  class TESObjectANIO;
  class TESIdleForm;
  class Actor;

  class AnimIdle : public NiRefObject
  {
    public:
      virtual ~AnimIdle();

      enum ANIM_IDLE_ENUM 
      {
        ANIM_IDLE_QUEUED = 0x0,
        ANIM_IDLE_LOADED = 0x1,
        ANIM_IDLE_PLAYING = 0x2,
        ANIM_IDLE_DONE_PLAYING = 0x3,
      };

      enum PLAY_TYPE_ENUM 
      {
        PLAY_TYPE_REPLACE = 0x0,
        PLAY_TYPE_QUEUE = 0x1,
        PLAY_TYPE_AUTO = 0x2,
        PLAY_TYPE_AUTO_EXCLUSIVE = 0x3,
      };

      ANIM_IDLE_ENUM eFlags;
      PLAY_TYPE_ENUM eType;
      NiPointer<KFModel> spKFModel;
      ANIM_GROUP_SECTION eSection;
      NiPointer<BSAnimGroupSequence> pSeq;
      TESObjectANIO *pAnimObj[2];
      NiPointer<NiAVObject> spAddOnObj[2];
      TESIdleForm *pIdleForm;
      Animation *pAnimation;
      Actor *pActor;
  };

  static_assert(sizeof(AnimIdle) == 0x38, "AnimIdle has wrong size");
  
} // namespace CommonLib
