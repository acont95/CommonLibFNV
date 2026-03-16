#pragma once
#include "Bethesda/TESForm.hpp"

namespace CommonLib {

  class TESObjectList;

  class TESObject : public TESForm {
    public:
      TESObject();
      ~TESObject();

      TESObjectList *m_pParentList;
      TESObject *nod_lpPrev;
      TESObject *nod_lpNext;
  };

  static_assert(sizeof(TESObject) == 0x24, "TESObject has wrong size");
  
} // namespace CommonLib
