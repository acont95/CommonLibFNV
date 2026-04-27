#pragma once
#include "Types.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Bethesda/IOTask.hpp"

namespace CommonLib {

  class QueuedChildren;
  class QueuedParents;

  class QueuedFile : public IOTask
  {
    public:

      MEM_CONTEXT eContext;
      NiPointer<QueuedFile> spParent;
      QueuedChildren* pChildren;
      QueuedParents* pAdditionalParents;
  };

  static_assert(sizeof(QueuedFile) == 0x28);
  
} // namespace CommonLib
