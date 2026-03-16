#pragma once

namespace CommonLib {

  class NiColor
  {
    public:
      NiColor();
      ~NiColor();

      float r;
      float g;
      float b;
  };

  static_assert(sizeof(NiColor) == 0xC, "NiColor has wrong size");
  
} // namespace CommonLib
