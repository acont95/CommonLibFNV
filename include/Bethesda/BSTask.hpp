#pragma once
#include <cstdint>

template <typename T>
class BSTask
{
  public:
    BSTask();
    virtual ~BSTask();

    enum BS_TASK_STATE
    {
      BS_TASK_STATE_PENDING = 0x0,
      BS_TASK_STATE_QUEUED = 0x1,
      BS_TASK_STATE_MOVING = 0x2,
      BS_TASK_STATE_RUNNING = 0x3,
      BS_TASK_STATE_FINISHED = 0x4,
      BS_TASK_STATE_COMPLETED = 0x5,
      BS_TASK_STATE_CANCELED = 0x6,
      BS_TASK_STATE_FORCE_DWORD = 0x7FFFFFFF,
    };

    volatile std::int32_t iRefCount;
    BS_TASK_STATE eState;
    T Key;
};

static_assert(sizeof(BSTask<std::int64_t>) == 0x18);
