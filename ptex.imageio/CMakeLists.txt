#
# Copyright (C) 2022  Autodesk, Inc. All Rights Reserved.
#
# SPDX-License-Identifier: Apache-2.0
#

INCLUDE(cxx_defaults)

SET(_target
    "ptex.imageio"
)

LIST(
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
  ptex/PtexWriter.cpp
)

ADD_LIBRARY(
  ${_target} SHARED
  ${_sources}
)

TARGET_LINK_LIBRARIES(
  ${_target}
  PUBLIC OpenImageIO ZLIB::ZLIB
)

IF(RV_TARGET_LINUX)
  SET(THREADS_PREFER_PTHREAD_FLAG
      TRUE
  )
  FIND_PACKAGE(Threads REQUIRED)
  TARGET_LINK_LIBRARIES(
    ${_target}
    PUBLIC Threads::Threads
  )
ELSEIF(RV_TARGET_WINDOWS)
  TARGET_LINK_LIBRARIES(
    ${_target}
    PUBLIC win_pthreads win_posix
  )
ENDIF()

IF(RV_TARGET_WINDOWS)
  TARGET_COMPILE_OPTIONS(
    ${_target}
    PRIVATE "-DPTEX_EXPORTS=1"
  )
ENDIF()

RV_STAGE(TYPE "OIIO_PLUGIN" TARGET ${_target})
