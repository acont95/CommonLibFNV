#pragma once

class ActorValueOwner
{
  public:
    ActorValueOwner();
    virtual ~ActorValueOwner();
};

static_assert(sizeof(ActorValueOwner) == 0x4, "ActorValueOwner has wrong size");
