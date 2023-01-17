#
# Copyright (C) 2022  Autodesk, Inc. All Rights Reserved.
#
# SPDX-License-Identifier: Apache-2.0
#

include(cxx_defaults)

set(_target "jpeg.imageio")

list(APPEND _sources jpeginput.cpp jpegoutput.cpp)

add_library(${_target} SHARED ${_sources})

target_include_directories(${_target} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${_target} PUBLIC OpenImageIO jpeg)

rv_stage(TYPE "OIIO_PLUGIN" TARGET ${_target})
