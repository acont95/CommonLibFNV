#pragma once
#include <cstdint>
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
      virtual std::uint16_t GetActorLevel();
  };

  static_assert(sizeof(ActorValueOwner) == 0x4, "ActorValueOwner has wrong size");
  
} // namespace CommonLib
