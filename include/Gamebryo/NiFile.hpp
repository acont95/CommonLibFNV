#pragma once
#include <cstdint>
#include <cstdio>
#include <windows.h>
#include "Gamebryo/NiBinaryStream.hpp"

class NiFile : public NiBinaryStream {
  public:
    NiFile();
    ~NiFile();

    virtual void Seek(std::int32_t iOffset, std::int32_t iWhence);
    virtual const char*	GetFilename() const;
    virtual std::uint32_t GetFileSize();

    enum OpenMode
    {
      READ_ONLY = 0x0,
      WRITE_ONLY = 0x1,
      APPEND_ONLY = 0x2,
    };

    std::uint32_t m_uiBufferAllocSize;
    std::uint32_t m_uiBufferReadSize;
    std::uint32_t m_uiPos;
    std::uint32_t m_uiCurrentFilePos;
    char*		m_pBuffer;
    FILE*		m_pFile;
    OpenMode	m_eMode;
    bool		m_bGood;
};

static_assert(sizeof(NiFile) == 0x30, "NiFile has wrong size");
