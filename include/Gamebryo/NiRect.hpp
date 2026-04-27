#pragma once

namespace CommonLib {

  template <typename T>
  class NiRect
  {
    public:

      T m_left;
      T m_right;
      T m_top;
      T m_bottom;
  };

  static_assert(sizeof(NiRect<float>) == 0x10, "NiRect has wrong size");
  
} // namespace CommonLib
