#pragma once

class NiThreadProcedure
{
  public:
    NiThreadProcedure();
    virtual ~NiThreadProcedure();
};

static_assert(sizeof(NiThreadProcedure) == 0x4, "NiThreadProcedure has wrong size");
