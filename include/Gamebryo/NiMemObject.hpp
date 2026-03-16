#pragma once

namespace CommonLib {

  class NiMemObject
  {
    public:
      NiMemObject();
      ~NiMemObject();
  };

  static_assert(sizeof(NiMemObject) == 0x1, "NiMemObject has wrong size");
  
} // namespace CommonLib
