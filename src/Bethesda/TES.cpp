#include "Bethesda/TES.hpp"

namespace CommonLib {

  TES* TES::GetTESSingleton() {
    return *reinterpret_cast<TES**>(0x011DEA10);
  }

} // namespace CommonLib
