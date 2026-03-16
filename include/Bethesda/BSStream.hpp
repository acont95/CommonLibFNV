#pragma once
#include <cstdint>
#include "Bethesda/BSNodeReferences.hpp"
#include "Gamebryo/NiStream.hpp"

namespace CommonLib {

  class NiObjectNET;
  template <typename T>
  class NiTStringMap;

  class BSStream : public NiStream
  {
    public:
      BSStream();
      virtual ~BSStream();

      enum OBJECT_REF_LEVELS
      {
        ORL_BASIC = 0x0,
        ORL_CHILDREN = 0x1,
        ORL_CHILDNODES = 0x3,
        ORL_PROPERTIES = 0x4,
        ORL_EFFECTS = 0x8,
        ORL_TEXTURES = 0x10,
        ORL_LEVELMASK = 0x1F,
        ORL_ALL = 0x1F,
      };

      enum OBJECTREFFLAGS
      {
        ORF_ADDING = 0x80,
      };

      NiTStringMap<NiObjectNET*>* pObjectRefMap;
      NiPointer<BSNodeReferences> spNodeReferences;
  };

  static_assert(sizeof(BSStream) == 0x5CC, "BSStream has wrong size");
    
} // namespace CommonLib
