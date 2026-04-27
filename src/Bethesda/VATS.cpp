#include <cmath>
#include "Bethesda/VATS.hpp"

namespace CommonLib {

  VATS* VATS::GetVATSSingleton() {
    return reinterpret_cast<VATS*>(0x011F2250);
  }

} // namespace CommonLib
