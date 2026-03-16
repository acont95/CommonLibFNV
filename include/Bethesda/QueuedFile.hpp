#pragma once
#include "Types.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Bethesda/IOTask.hpp"

class QueuedChildren;
class QueuedParents;

class QueuedFile : public IOTask
{
  public:
    QueuedFile();
    ~QueuedFile();

    MEM_CONTEXT eContext;
    NiPointer<QueuedFile> spParent;
    QueuedChildren* pChildren;
    QueuedParents* pAdditionalParents;
};

static_assert(sizeof(QueuedFile) == 0x28);
