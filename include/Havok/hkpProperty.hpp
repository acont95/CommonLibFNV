#pragma once
#include <cstdint>
#include "Havok/hkpPropertyValue.hpp"

namespace CommonLib {

  class hkpProperty 
  {
    public:
      hkpProperty();
      ~hkpProperty();

      unsigned int m_key;
      unsigned int m_alignmentPadding;
      hkpPropertyValue m_value;
  };

  static_assert(sizeof(hkpProperty) == 0x10, "hkpProperty has wrong size");
  
} // namespace CommonLib
