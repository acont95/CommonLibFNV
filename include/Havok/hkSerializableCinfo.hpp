#pragma once

namespace CommonLib {

  class hkSerializableCinfo
  {
    public:
      hkSerializableCinfo();
      ~hkSerializableCinfo();
  };

  static_assert(sizeof(hkSerializableCinfo) == 0x1, "hkSerializableCinfo has wrong size");
  
} // namespace CommonLib
