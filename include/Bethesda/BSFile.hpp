#pragma once
#include <cstdint>
#include <windows.h>
#include <Gamebryo/NiFile.hpp>

class BSFile : NiFile
{  
  public:
    BSFile();
    ~BSFile();

    bool m_bUseNoBuffering;
    bool bUseAuxBuffer;
    char* m_pAuxBuffer;
    std::int32_t iAuxTrueFilePos;
    std::uint32_t iAuxBufferMinIndex;
    std::uint32_t iAuxBufferMaxIndex;
    char pFileName[260];
    std::int32_t iResult;
    std::uint32_t iIOSize;
    std::uint32_t iTrueFilePos;
    std::uint32_t iFileSize;
};

static_assert(sizeof(BSFile) == 0x158, "BSFile has wrong size");
