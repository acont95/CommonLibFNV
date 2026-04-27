#include "Bethesda/PlayerCharacter.hpp"

namespace CommonLib {

  PlayerCharacter::~PlayerCharacter() = default;

  PlayerCharacter* PlayerCharacter::GetPlayerSingleton() {
    return *reinterpret_cast<PlayerCharacter**>(0x011DEA3C);
  }

} // namespace CommonLib
