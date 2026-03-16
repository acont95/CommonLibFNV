cmake_minimum_required(VERSION 3.24)
project(FNVCommonLib)

# Header-only library
add_library(FNVCommonLib INTERFACE)

# Collect all headers recursively
file(GLOB_RECURSE FNV_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
)

target_sources(FNVCommonLib INTERFACE
    FILE_SET HEADERS
    BASE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include"
    FILES ${FNV_HEADERS}
)

# Include directories
target_include_directories(FNVCommonLib INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Verify headers at build
set_property(TARGET FNVCommonLib PROPERTY
    VERIFY_INTERFACE_HEADER_SETS TRUE
)
