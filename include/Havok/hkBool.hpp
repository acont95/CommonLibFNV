#pragma once

namespace CommonLib {

  class hkBool
  {
    public:
      hkBool();
      ~hkBool();

      char m_bool;
  };

  static_assert(sizeof(hkBool) == 0x1, "hkBool has wrong size");
  
} // namespace CommonLib
