#
# Copyright (C) 2022  Autodesk, Inc. All Rights Reserved.
#
# SPDX-License-Identifier: Apache-2.0
#

include(cxx_defaults)

set(_target "ptex.imageio")

list(
  APPEND
  _sources
  ptexinput.cpp
  ptexoutput.cpp
  ptex/PtexCache.cpp
  ptex/PtexFilters.cpp
  ptex/PtexHalf.cpp
  ptex/PtexReader.cpp
  ptex/PtexSeparableFilter.cpp
  ptex/PtexSeparableKernel.cpp
  ptex/PtexTriangleFilter.cpp
  ptex/PtexTriangleKernel.cpp
  ptex/PtexUtils.cpp
  ptex/PtexWriter.cpp)

add_library(${_target} SHARED ${_sources})

target_link_libraries(${_target} PUBLIC OpenImageIO ZLIB::ZLIB)

if(RV_TARGET_LINUX)
  set(THREADS_PREFER_PTHREAD_FLAG TRUE)
  find_package(Threads REQUIRED)
  target_link_libraries(${_target} PUBLIC Threads::Threads)
elseif(RV_TARGET_WINDOWS)
  target_link_libraries(${_target} PUBLIC win_pthreads win_posix)
endif()

if(RV_TARGET_WINDOWS)
  target_compile_options(${_target} PRIVATE "-DPTEX_EXPORTS=1")
endif()

rv_stage(TYPE "OIIO_PLUGIN" TARGET ${_target})
