#pragma once
#include <cstdint>

namespace CommonLib {

  class TESPackage;
  class ActorPackageData;
  class TESObjectREFR;

  class ActorPackage
  {
    public:

      TESPackage *pPackage;
      ActorPackageData *pData;
      TESObjectREFR *pTarget;
      std::int32_t iCurrentProcedureIndex;
      float fPackageStartTime;
      std::uint32_t iFlags;
  };

  static_assert(sizeof(ActorPackage) == 0x18, "ActorPackage has wrong size");
  
} // namespace CommonLib
