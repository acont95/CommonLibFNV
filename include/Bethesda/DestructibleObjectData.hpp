#pragma once
#include <cstdint>
#include "Gamebryo/NiPointer.hpp"
#include "Bethesda/QueuedFile.hpp"

namespace CommonLib {

  class DestructibleObjectStage;

  class DestructibleObjectData
  {
    public:
      DestructibleObjectData();
      ~DestructibleObjectData();

      uint32_t iHealth;
      uint8_t cNumStages;
      uint8_t cFlags;
      DestructibleObjectStage** pStagesArray;
      volatile std::int32_t iReplacementModelRefCount;
      NiPointer<QueuedFile> spPreloadedReplacementModels;
  };

  static_assert(sizeof(DestructibleObjectData) == 0x14);
  
} // namespace CommonLib
