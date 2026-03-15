#pragma once
#include <cstdint>
#include <windows.h>
#include "Types.hpp"
#include "Bethesda/TESObjectCell.hpp"
#include "Bethesda/BSStringT.hpp"
#include "Bethesda/BSFile.hpp"
#include "Bethesda/TESObjectCell.hpp"
#include "Gamebryo/NiTPointerMap.hpp"

class TESFile {
  public:
    TESFile();
    ~TESFile();

    struct FORM
    {
      std::uint32_t form;
      std::uint32_t length;
      std::uint32_t flags;
      std::uint32_t iFormID;
      std::uint32_t iVersionControl;
      std::uint16_t sFormVersion;
      std::uint16_t sVCVersion;
    };

    struct FORM_GROUP
    {
      FORM GroupData;
      std::uint32_t iGroupOffset;
    };

    struct FILE_HEADER
    {
      float fVersion;
      std::uint32_t iFormCount;
      std::uint32_t iNextFormID;
    };

    TES_RETURN_CODE m_lastError;
    TESFile* pThreadSafeParent;
    NiTPointerMap<std::uint32_t,TESFile *> *pThreadSafeFileMap;
    BSFile *m_pLockedFile;
    BSFile *m_pFile;
    struct TESBitArrayFile *pFormUserDataBitArray;
    struct TESBitArrayFile *pFormVersionBitArray;
    struct TESBitArrayFile *pFormIDBitArray;
    char m_Filename[260];
    char m_Path[260];
    char *m_pBuffer;
    std::uint32_t m_uiBufferAllocSize;
    std::uint32_t m_firstCellOffset;
    std::uint32_t m_currCellOffset;
    TESObjectCELL *m_pCurrCell;
    std::uint32_t m_currRefOffset;
    FORM m_currentform;
    CHUNK_ID m_currentchunkID;
    std::uint32_t m_actualChunkSize;
    std::uint32_t m_filesize;
    std::uint32_t m_fileoffset;
    std::uint32_t m_formoffset;
    std::uint32_t m_chunkoffset;
    FORM m_saveform;
    std::uint32_t m_saveformoffset;
    std::uint32_t m_savechunkoffset;
    BSSimpleList<FORM_GROUP *> m_grouplist;
    bool bHasGroups;
    bool bMustEndianConvert;
    bool bCloseFileOverride;
    std::uint8_t pad01;
    _WIN32_FIND_DATAA m_FileInfo;
    FILE_HEADER fileHeaderInfo;
    std::uint32_t m_Flags;
    BSSimpleList<char *> listMasters;
    BSSimpleList<_ULARGE_INTEGER *> listMastersData;
    std::uint32_t iMasterCount;
    TESFile **m_pMasterPtrs;
    _FILETIME DeletedFormTime;
    std::uint8_t cCompileIndex;
    std::uint8_t pad02[3];
    BSStringT<char> cCreatedBy;
    BSStringT<char> cSummary;
    char *pDecompressedFormBuffer;
    std::uint32_t iDecompressedFormBufferSize;
    bool bCached;
    bool bCaching;
    bool bDLC;
    std::uint8_t pad03;
};

static_assert(sizeof(TESFile) == 0x42C, "TESFile has wrong size");
