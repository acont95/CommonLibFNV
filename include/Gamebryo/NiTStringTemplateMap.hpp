#pragma once
#include "Gamebryo/NiTMap.hpp"

namespace CommonLib {

  template <class TParent, typename T>
  class NiTStringTemplateMap : public TParent
  {
    public:
      NiTStringTemplateMap();
      virtual ~NiTStringTemplateMap();

      bool m_bCopy;
  };

  static_assert(sizeof(NiTStringTemplateMap<NiTMap<char const*, void*>, void*>) == 0x14, "NiTStringTemplateMap has wrong size");
  
} // namespace CommonLib
