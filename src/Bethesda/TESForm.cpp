#include <cmath>
#include "Bethesda/TESForm.hpp"

namespace CommonLib {

  static TESForm* GetFormByNumericId(int aiSearchID) {
    return CdeclCall<TESForm*>(0x004839C0, aiSearchID);
  }

  static TESForm* GetFormByEditorID(const char *apSearchID) {
    return CdeclCall<TESForm*>(0x00483A00, apSearchID);
  }

} // namespace CommonLib
