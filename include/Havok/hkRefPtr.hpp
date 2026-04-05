#pragma once

namespace CommonLib {

  template <typename T>
  class hkRefPtr
  {
    public:
      hkRefPtr();
      ~hkRefPtr();

      T *m_pntr;
  };

  static_assert(sizeof(hkRefPtr<void*>) == 0x4, "hkRefPtr has wrong size");
  
} // namespace CommonLib
