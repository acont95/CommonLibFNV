#pragma once
#include <cstdint>
#include "Havok/hkpPropertyValue.hpp"

namespace CommonLib {

  class hkpPropertyValue 
  {
    public:
      hkpPropertyValue();
      ~hkpPropertyValue();

      std::uint64_t m_data;
  };

  static_assert(sizeof(hkpPropertyValue) == 0x8, "hkpPropertyValue has wrong size");
  
} // namespace CommonLib
