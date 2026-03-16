#pragma once
#include "Gamebryo/NiNode.hpp"

namespace CommonLib {

  class BSNiNode : public NiNode
  {
    public:
      BSNiNode();
      virtual ~BSNiNode();
  };

  static_assert(sizeof(BSNiNode) == 0xAC, "BSNiNode has wrong size");
  
} // namespace CommonLib
