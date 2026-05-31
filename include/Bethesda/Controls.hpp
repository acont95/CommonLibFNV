#pragma once
#include <Windows.h>
#include <dinput.h>
#include <cstdint>

namespace CommonLib {

  struct _RUMBLE_TIMER
  {
    unsigned int uiRumbleDuration;
    unsigned int uiRampUpDuration;
    unsigned int uiRampDownDuration;
    unsigned int uiRumbleCounter;
    unsigned int uiRampCounter;
  };

  enum RUMBLE_PATTERN
  {
    CONSTANT = 0x0,
    PERIODIC_SQUARE = 0x1,
    PERIODIC_TRIANGLE = 0x2,
    PERIODIC_SAWTOOTH = 0x3,
    PERIODIC_SINE = 0x5,
    PERIODIC_TANGENT = 0x6,
  };

  struct _RUMBLE_EFFECT
  {
    struct RAMP
    {
      std::uint32_t uiDuration;
      std::uint16_t wStartSpeed;
      std::uint16_t wEndSpeed;
    };
    unsigned int uiSpeed;
    RUMBLE_PATTERN pattern;
    unsigned int uiDuration;
    unsigned int uiWavelength;
    bool bAlternate;
    RAMP RampUp;
    RAMP RampDown;
  };

  class XRumbleControl 
  {
    public:
      const std::int32_t iDevice;
      _RUMBLE_EFFECT *pLeftEffect;
      _RUMBLE_EFFECT *pRightEffect;
      _RUMBLE_TIMER LeftTimer;
      _RUMBLE_TIMER RightTimer;
      std::uint32_t dwNewTime;
      std::uint32_t dwOldTime;
      std::uint32_t dwStartTime;
  };

  struct MouseData {
    std::int32_t xDelta;
    std::int32_t yDelta;
    std::int32_t iMouseWheelScroll;
    bool   bCurrButtonStates[8];
  };

  struct JoystickData {
    std::uint32_t knownDeviceMask;
    std::uint32_t deviceClassMask;
  };

  struct JoystickState
  {
    DIJOYSTATE curr;
    DIJOYSTATE prev;
  };

  class Controls
  {
    public:
      int iEnable;
      std::uint32_t controlFlags;
      LPDIRECTINPUT8A pDirectInput;
      LPDIRECTINPUTDEVICE8A pJoysticks[8];
      LPDIRECTINPUTDEVICE8A pKeyboard;
      LPDIRECTINPUTDEVICE8A pMouse;
      JoystickState joystickStates[8];
      DIDEVICEINSTANCEA deviceInstances[8];
      DIDEVCAPS joystickCaps[8];
      JoystickData joystickData[8];
      std::uint32_t iNumJoysticks;
      std::uint8_t currKeyStates[256];
      std::uint8_t lastKeyStates[256];
      DIDEVCAPS mouseCaps;
      MouseData kCurrentMouseData;
      MouseData kLastMouseData;
      BOOL bSwapLeftRightMouseButtons;
      std::uint8_t cMouseSensitivity;
      char gap1B51[3];
      std::uint32_t uiDoubleClickTime;
      std::uint8_t mouseButtonStates[8];
      std::uint32_t unk1B60[8];
      XRumbleControl *sRumble;
      _RUMBLE_EFFECT *pRumbleEffect;
      bool isControllerEnabled;
      char gap1B89[3];
      std::uint32_t unk1B8C;
      char gap1B90[2];
      std::uint16_t usOverrideFlags;
      char ucKeyBinds[28];
      char ucMouseBinds[28];
      char ucJoystickBinds[28];
      char ucControllerBinds[28];
  };

  static_assert(sizeof(XRumbleControl) == 0x40, "XRumbleControl has wrong size");
  static_assert(sizeof(_RUMBLE_EFFECT) == 0x24, "_RUMBLE_EFFECT has wrong size");
  static_assert(sizeof(Controls) == 0x1C04, "Controls has wrong size");
    
} // namespace CommonLib
