#pragma once
#include <cstdint>

namespace CommonLib {

  class NiSearchPath
  {
    public:
      NiSearchPath();
      virtual ~NiSearchPath();

      std::uint32_t m_uiNextPath;
      char m_acFilePath[260];
      char m_acReferencePath[260];
  };

  static_assert(sizeof(NiSearchPath) == 0x210, "NiSearchPath has wrong size");
  
} // namespace CommonLib
