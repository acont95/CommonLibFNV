#pragma once
#include <cstdint>
#include "Gamebryo/NiProperty.hpp"

namespace CommonLib {

  class NiShadeProperty : public NiProperty
  {
    public:
      NiShadeProperty();
      virtual ~NiShadeProperty();

      std::uint16_t m_uFlags;
      std::int32_t iShaderPropertyType;
  };

  static_assert(sizeof(NiShadeProperty) == 0x20, "NiShadeProperty has wrong size");
  
} // namespace CommonLib
