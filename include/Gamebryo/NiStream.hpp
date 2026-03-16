#pragma once
#include <cstdint>
#include "Bethesda/BSStreamHeader.hpp"
#include "Gamebryo/NiTLargeObjectArray.hpp"
#include "Gamebryo/NiTLargePrimitiveArray.hpp"
#include "Gamebryo/NiTPrimitiveSet.hpp"
#include "Gamebryo/NiTPointerMap.hpp"
#include "Gamebryo/NiFixedString.hpp"
#include "Gamebryo/NiThread.hpp"
#include "Gamebryo/NiThreadProcedure.hpp"
#include "Gamebryo/NiTPrimitiveArray.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiObject.hpp"

namespace CommonLib {

  class NiSearchPath;
  class NiBinaryStream;
  class NiObjectGroup;

  class NiStream
  {
    public:
      NiStream();
      virtual ~NiStream();

      enum ThreadStatus
      {
        PAUSING = 0x3,
      };

      class BackgroundLoadProcedure : NiThreadProcedure
      {
        public:
          BackgroundLoadProcedure();
          virtual ~BackgroundLoadProcedure();
          NiStream *m_pkStream;
      };

      BSStreamHeader m_BSStreamHeader;
      NiTPrimitiveArray<NiObjectGroup *> m_kGroups;
      std::uint32_t m_uiNifFileVersion;
      std::uint32_t m_uiNifFileUserDefinedVersion;
      char m_acFileName[260];
      bool m_bSaveLittleEndian;
      bool m_bSourceIsLittleEndian;
      NiSearchPath *m_pkSearchPath;
      NiTLargeObjectArray<NiPointer<NiObject> > m_kObjects;
      NiTLargePrimitiveArray<std::uint32_t> m_kObjectSizes;
      NiTLargeObjectArray<NiPointer<NiObject> > m_kTopObjects;
      NiTLargeObjectArray<NiFixedString> m_kFixedStrings;
      NiBinaryStream *m_pkIstr;
      NiBinaryStream *m_pkOstr;
      NiTPrimitiveSet<std::uint32_t> m_kLinkIDs;
      std::uint32_t m_uiLinkIndex;
      NiTPrimitiveSet<std::uint32_t> m_kLinkIDBlocks;
      std::uint32_t m_uiLinkBlockIndex;
      NiTPointerMap<NiObject const *,std::uint32_t> m_kRegisterMap;
      std::uint16_t m_usNiAVObjectFlags;
      std::uint16_t m_usNiTimeControllerFlags;
      std::uint16_t m_usNiPropertyFlags;
      NiStream::ThreadStatus m_eBackgroundLoadStatus;
      bool m_bBackgroundLoadExitStatus;
      std::uint32_t m_uiLoad;
      std::uint32_t m_uiLink;
      std::uint32_t m_uiPostLink;
      NiThread *m_pkThread;
      NiStream::BackgroundLoadProcedure *m_pkBGLoadProc;
      NiThread::Priority m_ePriority;
      NiProcessorAffinity m_kAffinity;
      char m_acLastLoadedRTTI[260];
      std::uint32_t m_uiLastError;
      char m_acLastErrorMessage[260];
      char m_acFilePath[260];

  };

  static_assert(sizeof(NiStream) == 0x5C4, "NiStream has wrong size");
  
} // namespace CommonLib
