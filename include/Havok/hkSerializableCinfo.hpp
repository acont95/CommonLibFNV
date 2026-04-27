#pragma once

namespace CommonLib {

  class hkSerializableCinfo
  {
    public:

  };

  static_assert(sizeof(hkSerializableCinfo) == 0x1, "hkSerializableCinfo has wrong size");
  
} // namespace CommonLib
