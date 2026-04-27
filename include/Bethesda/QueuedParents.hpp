#pragma once
#include <cstdint>
#include "Bethesda/QueuedFile.hpp"
#include "Bethesda/BSSimpleArray.hpp"

namespace CommonLib {

  class QueuedParents : public BSSimpleArray<NiPointer<QueuedFile>, 1024>
  {
    public:

  };

  static_assert(sizeof(QueuedParents) == 0x10);
  
} // namespace CommonLib
