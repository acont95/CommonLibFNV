#pragma once
#include <cstdint>
#include "Bethesda/BSTask.hpp"

class IOTask : public BSTask<std::int64_t>
{
  public:
    IOTask();
    ~IOTask();
};

static_assert(sizeof(IOTask) == 0x18);
