#pragma once
#include "Gamebryo/NiMemObject.hpp"

class NiObjectGroup : public NiMemObject {
  public:
    NiObjectGroup();
    ~NiObjectGroup();

    unsigned int m_uiSize;
    void* m_pvBuffer;
    void* m_pvFree;
    unsigned int m_uiRefCount;
};

static_assert(sizeof(NiObjectGroup) == 0x10, "NiObjectGroup has wrong size");
