#pragma once
#include "Bethesda/QueuedFileEntry.hpp"
#include "Bethesda/BSStream.hpp"

class GrassLoadTask : public QueuedFileEntry
{
  public:
    GrassLoadTask();
    virtual ~GrassLoadTask();

    BSStream m_kStream;
};

static_assert(sizeof(GrassLoadTask) == 0x600, "GrassLoadTask has wrong size");
