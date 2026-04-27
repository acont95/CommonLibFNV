#pragma once
#include <cstdint>
#include "Gamebryo/NiRefObject.hpp"
#include "Gamebryo/NiFixedString.hpp"

namespace CommonLib {

  class NiShader : public NiRefObject
  {
    public:

      NiFixedString m_kName;
      std::uint32_t m_uiImplementation;
      bool m_bInitialized;
  };

  static_assert(sizeof(NiShader) == 0x14, "NiShader has wrong size");
  
} // namespace CommonLib
