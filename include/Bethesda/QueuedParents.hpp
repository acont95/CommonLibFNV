#pragma once
#include <cstdint>
#include "Bethesda/QueuedFile.hpp"
#include "Bethesda/BSSimpleArray.hpp"

class QueuedParents : BSSimpleArray<NiPointer<QueuedFile>, 1024>
{
  public:
    QueuedParents();
    ~QueuedParents();
};

static_assert(sizeof(QueuedParents) == 0x10);
