#pragma once

namespace CommonLib {

  class ActorValueOwner
  {
    public:
      virtual ~ActorValueOwner();
  };

  static_assert(sizeof(ActorValueOwner) == 0x4, "ActorValueOwner has wrong size");
  
} // namespace CommonLib
