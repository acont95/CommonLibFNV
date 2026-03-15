cmake_minimum_required(VERSION 3.20)
project(FNVCommonLib)
add_library(FNVCommonLib INTERFACE)
target_include_directories(FNVCommonLib INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
