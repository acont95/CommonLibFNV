#pragma once
#include "Bethesda/BSStringT.hpp"
#include "Bethesda/BaseFormComponent.hpp"

class TESSoundFile : BaseFormComponent {
  public:
    TESSoundFile();
    ~TESSoundFile();

    BSStringT<char> cSoundFile;
};

static_assert(sizeof(TESSoundFile) == 0xC, "TESSoundFile has wrong size");
