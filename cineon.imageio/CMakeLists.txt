#
# Copyright (C) 2022  Autodesk, Inc. All Rights Reserved.
#
# SPDX-License-Identifier: Apache-2.0
#

include(cxx_defaults)

set(_target "cineon.imageio")

list(
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
  libcineon/Writer.cpp)

add_library(${_target} SHARED ${_sources})

target_include_directories(${_target} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${_target} PUBLIC OpenImageIO)

rv_stage(TYPE "OIIO_PLUGIN" TARGET ${_target})
