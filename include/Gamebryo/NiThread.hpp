#pragma once
#include <cstdint>
#include "Gamebryo/NiProcessorAffinity.hpp"

class NiThreadProcedure;

class NiThread
{
  public:
    NiThread();
    virtual ~NiThread();

    enum Priority : std::int32_t
    {
      LOWEST = 0x1,
      BELOW_NORMAL = 0x2,
      ABOVE_NORMAL = 0x4,
      HIGHEST = 0x5,
      TIME_CRITICAL = 0x6,
      NUM_PRIORITIES = 0x7,
    };

    volatile enum Status : std::int32_t
    {
      SUSPENDED = 0x1,
      COMPLETE = 0x2,
    };

    std::uint32_t m_iThreadID;
    NiProcessorAffinity m_kAffinity;
    std::uint32_t m_uiStackSize;
    NiThreadProcedure* m_pkProcedure;
    Priority m_ePriority;
    volatile NiThread::Status m_eStatus;
    volatile std::uint32_t m_uiReturnValue;
    void* m_hThread;
    char* m_pcName;
};

static_assert(sizeof(NiThread) == 0x2C, "NiThread has wrong size");
