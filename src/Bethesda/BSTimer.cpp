#include "Bethesda/BSTimer.hpp"

namespace CommonLib {

  BSTimer* BSTimer::GetAppTimerSingleton() {
    return reinterpret_cast<BSTimer*>(0x011F6394);
  }

} // namespace CommonLib
