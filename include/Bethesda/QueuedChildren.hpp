#pragma once
#include <cstdint>
#include "Bethesda/QueuedFile.hpp"
#include "Bethesda/BSSimpleArray.hpp"

namespace CommonLib {

  class QueuedChildren : public BSSimpleArray<NiPointer<QueuedFile>, 1024>
  {
    public:

      volatile std::uint32_t iNumChildrenFinished;
  };

  static_assert(sizeof(QueuedChildren) == 0x14);
  
} // namespace CommonLib
