#pragma once
#include <cstdint>

class BSStreamHeader
{
  public:
    BSStreamHeader();
    ~BSStreamHeader();
    
    std::uint32_t uiVersion;
    char pAuthor[64];
    char pProcessScript[64];
    char pExportScript[64];
};

static_assert(sizeof(BSStreamHeader) == 0xC4, "BSStreamHeader has wrong size");
