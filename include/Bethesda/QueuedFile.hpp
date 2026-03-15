#pragma once
#include "Types.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Bethesda/IOTask.hpp"
#include "Bethesda/QueuedChildren.hpp"
#include "Bethesda/QueuedParents.hpp"

class QueuedFile : IOTask
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
