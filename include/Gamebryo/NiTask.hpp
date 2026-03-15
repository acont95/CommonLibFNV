#pragma once
#include "Gamebryo/NiObject.hpp"

class NiTask : NiObject
{
  public:
    NiTask();
    virtual ~NiTask();

    enum TaskStatus : __int32
    {
      RUNNING = 0x2,
      COMPLETED = 0x3,
      ABORTED = 0x4,
    };

    NiTask::TaskStatus m_eStatus;
};

static_assert(sizeof(NiTask) == 0xC, "NiTask has wrong size");
