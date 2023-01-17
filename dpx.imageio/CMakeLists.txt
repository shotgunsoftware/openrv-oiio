#
# Copyright (C) 2022  Autodesk, Inc. All Rights Reserved.
#
# SPDX-License-Identifier: Apache-2.0
#

INCLUDE(cxx_defaults)

SET(_target
    "dpx.imageio"
)

LIST(
  APPEND
  _sources
  dpxinput.cpp
  dpxoutput.cpp
  libdpx/Codec.cpp
  libdpx/DPX.cpp
  libdpx/DPXColorConverter.cpp
  libdpx/DPXHeader.cpp
  libdpx/ElementReadStream.cpp
  libdpx/InStream.cpp
  libdpx/OutStream.cpp
  libdpx/Reader.cpp
  libdpx/RunLengthEncoding.cpp
  libdpx/Writer.cpp
)

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
)
RV_STAGE(TYPE "OIIO_PLUGIN" TARGET ${_target})
