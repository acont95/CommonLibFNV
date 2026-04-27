#pragma once

namespace CommonLib {

  class NiFixedString {
    public:

      char *m_kHandle;
  };

  static_assert(sizeof(NiFixedString) == 0x4, "NiFixedString has wrong size");
  
} // namespace CommonLib
