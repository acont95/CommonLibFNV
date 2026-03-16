#pragma once
#include "Gamebryo/NiTask.hpp"

namespace CommonLib {

  class NiXenonRendererTask : public NiTask
  {
    public:
      NiXenonRendererTask();
      virtual ~NiXenonRendererTask();
  };

  static_assert(sizeof(NiXenonRendererTask) == 0xC, "NiXenonRendererTask has wrong size");
  
} // namespace CommonLib
