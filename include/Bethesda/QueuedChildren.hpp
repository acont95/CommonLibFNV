#pragma once
#include <cstdint>
#include "Bethesda/BSSimpleArray.hpp"
#include "Bethesda/QueuedFile.hpp"
#include "Gamebryo/NiPointer.hpp"

class QueuedChildren : BSSimpleArray<NiPointer<QueuedFile>, 1024>
{
  public:
    QueuedChildren();
    ~QueuedChildren();

    volatile std::uint32_t iNumChildrenFinished;
};

static_assert(sizeof(QueuedChildren) == 0x14);
