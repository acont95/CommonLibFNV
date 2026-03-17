#pragma once
#include "Types.hpp"
#include "Gamebryo/NiTPointerMap.hpp"
#include "Gamebryo/NiTStringTemplateMap.hpp"

namespace CommonLib {

  template <typename T>
  class NiTStringPointerMap : public NiTStringTemplateMap<NiTPointerMap<char const *, T>, T>
  {
    public:
      NiTStringPointerMap();
      virtual ~NiTStringPointerMap();
  };

  static_assert(sizeof(NiTStringPointerMap<void>) == 0x14, "NiTStringPointerMap has wrong size");
  
} // namespace CommonLib
