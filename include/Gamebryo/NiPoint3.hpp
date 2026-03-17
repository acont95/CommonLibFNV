#pragma once

namespace CommonLib {

  class NiPoint3
  {
    public:
      float x;
      float y;
      float z;
  };

  static_assert(sizeof(NiPoint3) == 0xC, "NiPoint3 has wrong size");
  
} // namespace CommonLib
