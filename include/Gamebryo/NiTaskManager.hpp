#pragma once
#include <cstdint>
#include "Gamebryo/NiObject.hpp"
#include "Gamebryo/NiTPrimitiveQueue.hpp"
#include "Gamebryo/NiCriticalSection.hpp"

namespace CommonLib {

  class NiTask;

  class NiTaskManager : public NiObject
  {
    public:
      virtual ~NiTaskManager();

      enum TaskPriority
      {
        IMMEDIATE = 0x3,
      };

      enum ManagerStatus
      {
        STOPPED = 0x0,
        STOPPING = 0x1,
      };

      NiTPrimitiveQueue<NiTask*> m_akTaskQueues[4];
      NiCriticalSection m_kManagerLock;
      NiTaskManager::ManagerStatus m_eStatus;
  };

  static_assert(sizeof(NiTaskManager) == 0x6C, "NiTaskManager has wrong size");
  
} // namespace CommonLib
