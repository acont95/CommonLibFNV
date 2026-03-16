#pragma once
#include <cstdint>
#include "Bethesda/hkBaseObject.hpp"

class hkReferencedObject : public hkBaseObject
{
  public:
    hkReferencedObject();
    ~hkReferencedObject();

    std::uint16_t m_memSizeAndFlags;
    std::int16_t m_referenceCount;
};

static_assert(sizeof(hkReferencedObject) == 0x8, "hkReferencedObject has wrong size");
