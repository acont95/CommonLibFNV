#pragma once
#include <cstdint>
#include "Bethesda/BSTask.hpp"

namespace CommonLib {

  class IOTask : public BSTask<std::int64_t>
  {
    public:

  };

  static_assert(sizeof(IOTask) == 0x18);
  
} // namespace CommonLib
