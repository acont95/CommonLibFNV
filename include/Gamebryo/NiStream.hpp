#pragma once
#include <cstdint>
#include "Bethesda/BSStreamHeader.hpp"
#include "Gamebryo/NiTPrimitiveArray.hpp"
#include "Gamebryo/NiSearchPath.hpp"
#include "Gamebryo/NiTLargeObjectArray.hpp"
#include "Gamebryo/NiTLargePrimitiveArray.hpp"
#include "Gamebryo/NiBinaryStream.hpp"
#include "Gamebryo/NiTPrimitiveSet.hpp"
#include "Gamebryo/NiTPointerMap.hpp"
#include "Gamebryo/NiProcessorAffinity.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiObject.hpp"
#include "Gamebryo/NiFixedString.hpp"
#include "Gamebryo/NiStream.hpp"
#include "Gamebryo/NiThread.hpp"
#include "Gamebryo/NiObjectGroup.hpp"

class NiStream
{
  public:
    NiStream();
    virtual ~NiStream();

    enum ThreadStatus : std::int32_t
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
    unsigned int m_uiNifFileVersion;
    unsigned int m_uiNifFileUserDefinedVersion;
    char m_acFileName[260];
    bool m_bSaveLittleEndian;
    bool m_bSourceIsLittleEndian;
    NiSearchPath *m_pkSearchPath;
    NiTLargeObjectArray<NiPointer<NiObject> > m_kObjects;
    NiTLargePrimitiveArray<unsigned int> m_kObjectSizes;
    NiTLargeObjectArray<NiPointer<NiObject> > m_kTopObjects;
    NiTLargeObjectArray<NiFixedString> m_kFixedStrings;
    NiBinaryStream *m_pkIstr;
    NiBinaryStream *m_pkOstr;
    NiTPrimitiveSet<unsigned int> m_kLinkIDs;
    unsigned int m_uiLinkIndex;
    NiTPrimitiveSet<unsigned int> m_kLinkIDBlocks;
    unsigned int m_uiLinkBlockIndex;
    NiTPointerMap<NiObject const *,unsigned int> m_kRegisterMap;
    std::uint16_t m_usNiAVObjectFlags;
    std::uint16_t m_usNiTimeControllerFlags;
    std::uint16_t m_usNiPropertyFlags;
    NiStream::ThreadStatus m_eBackgroundLoadStatus;
    bool m_bBackgroundLoadExitStatus;
    unsigned int m_uiLoad;
    unsigned int m_uiLink;
    unsigned int m_uiPostLink;
    NiThread *m_pkThread;
    NiStream::BackgroundLoadProcedure *m_pkBGLoadProc;
    NiThread::Priority m_ePriority;
    NiProcessorAffinity m_kAffinity;
    char m_acLastLoadedRTTI[260];
    unsigned int m_uiLastError;
    char m_acLastErrorMessage[260];
    char m_acFilePath[260];

};

static_assert(sizeof(NiStream) == 0x5C4, "NiStream has wrong size");
