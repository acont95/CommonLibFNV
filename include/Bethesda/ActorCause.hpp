#pragma once

#include "Gamebryo/NiPoint3.hpp"

// TODO
namespace CommonLib {

  class Actor;
  class DetectionState;
  template <typename T>
  class BSSimpleList;

  class ActorCause
  {
    public:

      Actor *pActor;
      BSSimpleList<DetectionState *> *pWitnesses;
      NiPoint3 kOrigin;
      int iActorCauseID;
      int iRefCount;
  };

  static_assert(sizeof(ActorCause) == 0x1C, "ActorCause has wrong size");
  
} // namespace CommonLib
