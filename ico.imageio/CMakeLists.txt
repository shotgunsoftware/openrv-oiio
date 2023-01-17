#
# Copyright (C) 2022  Autodesk, Inc. All Rights Reserved.
#
# SPDX-License-Identifier: Apache-2.0
#

INCLUDE(cxx_defaults)

SET(_target
    "ico.imageio"
)

LIST(APPEND _sources icoinput.cpp icooutput.cpp)

ADD_LIBRARY(
  ${_target} SHARED
  ${_sources}
)

TARGET_INCLUDE_DIRECTORIES(
  ${_target}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

TARGET_LINK_LIBRARIES(
  ${_target}
  PUBLIC OpenImageIO
  PRIVATE png_pvt
)

RV_STAGE(TYPE "OIIO_PLUGIN" TARGET ${_target})
