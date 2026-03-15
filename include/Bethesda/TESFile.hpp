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
    NiTPointerMap<unsigned int,TESFile *> *pThreadSafeFileMap;
    BSFile *m_pLockedFile;
    BSFile *m_pFile;
    struct TESBitArrayFile *pFormUserDataBitArray;
    struct TESBitArrayFile *pFormVersionBitArray;
    struct TESBitArrayFile *pFormIDBitArray;
    char m_Filename[260];
    char m_Path[260];
    char *m_pBuffer;
    unsigned int m_uiBufferAllocSize;
    unsigned int m_firstCellOffset;
    unsigned int m_currCellOffset;
    TESObjectCELL *m_pCurrCell;
    unsigned int m_currRefOffset;
    FORM m_currentform;
    CHUNK_ID m_currentchunkID;
    unsigned int m_actualChunkSize;
    unsigned int m_filesize;
    unsigned int m_fileoffset;
    unsigned int m_formoffset;
    unsigned int m_chunkoffset;
    FORM m_saveform;
    unsigned int m_saveformoffset;
    unsigned int m_savechunkoffset;
    BSSimpleList<FORM_GROUP *> m_grouplist;
    bool bHasGroups;
    bool bMustEndianConvert;
    bool bCloseFileOverride;
    std::uint8_t pad01;
    _WIN32_FIND_DATAA m_FileInfo;
    FILE_HEADER fileHeaderInfo;
    unsigned int m_Flags;
    BSSimpleList<char *> listMasters;
    BSSimpleList<_ULARGE_INTEGER *> listMastersData;
    unsigned int iMasterCount;
    TESFile **m_pMasterPtrs;
    _FILETIME DeletedFormTime;
    std::uint8_t cCompileIndex;
    std::uint8_t pad02[3];
    BSStringT<char> cCreatedBy;
    BSStringT<char> cSummary;
    char *pDecompressedFormBuffer;
    unsigned int iDecompressedFormBufferSize;
    bool bCached;
    bool bCaching;
    bool bDLC;
    std::uint8_t pad03;
};

static_assert(sizeof(TESFile) == 0x42C, "TESFile has wrong size");
