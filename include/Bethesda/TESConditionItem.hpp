#pragma once
#include <cstdint>

namespace CommonLib {

  class TESGlobal;
  class TESObjectREFR;

  class TESConditionItem
  {
    public:

      union GlobalData
      {
        TESGlobal* pGlobal;
        float fValue;
      };

      enum CONDITIONITEMOBJECT
      {
        CIO_SELF = 0x0,
        CIO_TARGET = 0x1,
        CIO_REF = 0x2,
        CIO_COMBATTARGET = 0x3,
        CIO_LINKEDREF = 0x4,
        CIO_COUNT = 0x5,
      };

      struct FUNCTION_DATA
      {
        std::uint16_t iFunction;
        void* pParam[2];
      };

      struct CONDITION_ITEM_DATA
      {
        char iFlags;
        GlobalData uGlobalData;
        FUNCTION_DATA FunctionData;
        CONDITIONITEMOBJECT eObject;
        TESObjectREFR* pRunOnRef;
      };

      CONDITION_ITEM_DATA Data;
  };

  static_assert(sizeof(TESConditionItem) == 0x1C, "TESConditionItem has wrong size");
  
} // namespace CommonLib
