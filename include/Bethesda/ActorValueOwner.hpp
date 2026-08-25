#pragma once
#include "Bethesda/ActorValue.hpp"

namespace CommonLib {

  class TESForm;

  class ActorValueOwner
  {
    public:
      virtual int GetBaseActorValue(ActorValue::Index);
      virtual float GetBaseActorFloatValue(ActorValue::Index);
      virtual int GetActorValue(ActorValue::Index);
      virtual float GetActorFloatValue(ActorValue::Index);
      virtual float GetTemporaryModifier(ActorValue::Index);
      virtual float GetDamageModifier(ActorValue::Index);
      virtual float GetPermanentModifier(ActorValue::Index);
      virtual int GetPermanentActorValue(ActorValue::Index);
      virtual float GetPermanentActorFloatValue(ActorValue::Index);
      virtual TESForm* GetAsForm();
      virtual unsigned __int16 GetActorLevel();
  };

  static_assert(sizeof(ActorValueOwner) == 0x4, "ActorValueOwner has wrong size");
  
} // namespace CommonLib
