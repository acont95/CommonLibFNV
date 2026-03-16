#pragma once

namespace CommonLib {

  class NiPoint4 
  {
    public:
      NiPoint4();
      ~NiPoint4();

      float x;
      float y;
      float z;
      float w;
  };

  static_assert(sizeof(NiPoint4) == 0x10, "NiPoint4 should be 16 bytes");
  
} // namespace CommonLib
