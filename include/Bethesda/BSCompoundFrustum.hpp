#pragma once
#include <cstdint>
#include "Bethesda/BSSimpleArray.hpp"
#include "Gamebryo/NiFrustumPlanes.hpp"
#include "Gamebryo/NiPoint3.hpp"

class BSFileEntry;

class BSCompoundFrustum {
  public:
    BSCompoundFrustum();
    ~BSCompoundFrustum();

    struct FunctionOp
    {
      std::int32_t op;
      std::int32_t jp;
      std::int32_t jf;
    };

    bool bPrethreaded;
    BSSimpleArray<NiFrustumPlanes,1024> kPlanes;
    BSSimpleArray<BSCompoundFrustum::FunctionOp, 1024> kFunctionOperators;
    std::int32_t iFreePlane;
    std::int32_t iFreeOp;
    std::int32_t iFirstOp;
    NiFrustumPlanes kViewFrustum;
    NiPoint3 kViewPosition;
    bool bSkipViewFrustum;
};

static_assert(sizeof(BSCompoundFrustum) == 0xA4, "BSCompoundFrustum has wrong size");

