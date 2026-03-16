#pragma once
#include <cstdint>
#include "Gamebryo/NiObject.hpp"

class NiTask : public NiObject
{
  public:
    NiTask();
    virtual ~NiTask();

    enum TaskStatus : std::int32_t
    {
      RUNNING = 0x2,
      COMPLETED = 0x3,
      ABORTED = 0x4,
    };

    NiTask::TaskStatus m_eStatus;
};

static_assert(sizeof(NiTask) == 0xC, "NiTask has wrong size");
