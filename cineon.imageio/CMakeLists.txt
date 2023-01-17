#
# Copyright (C) 2022  Autodesk, Inc. All Rights Reserved.
#
# SPDX-License-Identifier: Apache-2.0
#

INCLUDE(cxx_defaults)

SET(_target
    "cineon.imageio"
)

LIST(
  APPEND
  _sources
  cineoninput.cpp
  cineonoutput.cpp
  libcineon/Cineon.cpp
  libcineon/CineonHeader.cpp
  libcineon/Codec.cpp
  libcineon/ElementReadStream.cpp
  libcineon/InStream.cpp
  libcineon/OutStream.cpp
  libcineon/Reader.cpp
  libcineon/Writer.cpp
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
