#pragma once

namespace CommonLib {

  class hkBaseObject
  {
    public:
      hkBaseObject();
      virtual ~hkBaseObject();
  };

  static_assert(sizeof(hkBaseObject) == 0x4, "hkBaseObject has wrong size");
  
} // namespace CommonLib
