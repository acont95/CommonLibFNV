#pragma once
#include <cstdint>
#include "Havok/hkReferencedObject.hpp"
#include "Havok/hkVector4.hpp"
#include "Havok/hkArray.hpp"
#include "Havok/hkEnum.hpp"
#include "Havok/hkContainerHeapAllocator.hpp"

class hkpMoppCode : public hkReferencedObject
{
  public:
    hkpMoppCode();
    virtual ~hkpMoppCode();

    struct CodeInfo
    {
      hkVector4 m_offset;
    };

    enum BuildType : std::int32_t
    {
      BUILT_WITH_CHUNK_SUBDIVISION = 0x0,
      BUILT_WITHOUT_CHUNK_SUBDIVISION = 0x1,
      BUILD_NOT_SET = 0x2,
    };

    CodeInfo m_info;
    hkArray<unsigned char, hkContainerHeapAllocator> m_data;
    hkEnum<enum hkpMoppCode::BuildType, signed char> m_buildType;
};

static_assert(sizeof(hkpMoppCode) == 0x30, "hkpMoppCode has wrong size");
