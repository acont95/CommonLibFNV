#pragma once
#include "Bethesda/BSStringT.hpp"
#include "Bethesda/BaseFormComponent.hpp"

namespace CommonLib {

  class TESSoundFile : public BaseFormComponent {
    public:
      TESSoundFile();
      ~TESSoundFile();

      BSStringT<char> cSoundFile;
  };

  static_assert(sizeof(TESSoundFile) == 0xC, "TESSoundFile has wrong size");
  
} // namespace CommonLib
