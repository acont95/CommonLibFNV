#pragma once
#include <cstdint>
#include "Types.hpp"
#include "Havok/hkReferencedObject.hpp"
#include "Havok/hkBool.hpp"

namespace CommonLib {

  class hkpCharacterStateManager;

  class hkpCharacterContext : public hkReferencedObject
  {
    public:
      hkpCharacterContext();
      virtual ~hkpCharacterContext();

      enum CharacterType : std::int32_t
      {
        HK_CHARACTER_PROXY = 0x0,
        HK_CHARACTER_RIGIDBODY = 0x1,
      };

      CharacterType m_characterType;
      const hkpCharacterStateManager *m_stateManager;
      hkpCharacterStateType m_currentState;
      hkpCharacterStateType m_previousState;
      hkBool m_filterEnable;
      float m_maxLinearAcceleration;
      float m_maxLinearVelocity;
      float m_gain;
  };

  static_assert(sizeof(hkpCharacterContext) == 0x28, "hkpCharacterContext has wrong size");
  
} // namespace CommonLib
