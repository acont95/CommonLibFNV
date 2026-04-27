#pragma once

namespace CommonLib {

  template <typename T>
  class hkPadSpu
  {
    public:

      float m_storage;
  };

  static_assert(sizeof(hkPadSpu<void *>) == 0x4, "hkPadSpu has wrong size");
  
} // namespace CommonLib
