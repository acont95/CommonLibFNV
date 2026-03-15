#pragma once
#include "Havok/hkBaseObject.hpp"

class hkReferencedObject : hkBaseObject
{
  public:
    hkReferencedObject();
    virtual ~hkReferencedObject();

    unsigned __int16 m_memSizeAndFlags;
    __int16 m_referenceCount;
};

static_assert(sizeof(hkReferencedObject) == 0x8, "hkReferencedObject has wrong size");
