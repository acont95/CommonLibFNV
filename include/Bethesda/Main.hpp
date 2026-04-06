#pragma once
#include <Windows.h>
#include "Bethesda/ScrapHeap.hpp"
#include "Bethesda/BSPackedTaskQueue.hpp"
#include "Gamebryo/NiAVObject.hpp"
#include "Gamebryo/NiFrustum.hpp"
#include "Gamebryo/NiRect.hpp"

namespace CommonLib {

  class CustomLaunchData;
  class BSShaderAccumulator;
  class NiCamera;

  class Main
  {
    public:
      Main();
      ~Main();

      bool bResumeLoadingThread;
      bool bQuitGame;
      bool bResetGame;
      bool bGameActive;
      bool bOnIdle;
      bool bReloadContent;
      bool bFlyCamera;
      bool bFreezeTime;
      HWND *hWnd;
      HINSTANCE *hInstance;
      unsigned int iThreadID;
      void *hThreadHandle;
      ScrapHeap PackedTaskHeap;
      BSPackedTaskQueue TaskQueue;
      ScrapHeap SecondaryPackedTaskHeap;
      BSPackedTaskQueue SecondaryTaskQueue;
      NiPointer<BSShaderAccumulator> spDrawWorldAccum;
      NiPointer<BSShaderAccumulator> spDraw1stPersonAccum;
      NiPointer<BSShaderAccumulator> spDraw1stPersonDepthAccum;
      NiPointer<BSShaderAccumulator> spScreenSplatterAccum;
      NiPointer<BSShaderAccumulator> spRenderedMenuAccum;
      bool bRenderingMenuBG;
      NiPointer<NiCamera> sp1stPersonAdjustedCamera;
  };

  static_assert(sizeof(Main) == 0xA4, "Main has wrong size");
  
} // namespace CommonLib
