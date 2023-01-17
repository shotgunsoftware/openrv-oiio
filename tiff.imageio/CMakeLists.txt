#
# Copyright (C) 2022  Autodesk, Inc. All Rights Reserved.
#
# SPDX-License-Identifier: Apache-2.0
#

include(cxx_defaults)

set(_target "tiff.imageio")

list(APPEND _sources tiffinput.cpp tiffoutput.cpp)

add_library(${_target} SHARED ${_sources})

target_link_libraries(${_target} PRIVATE OpenImageIO tiff)

rv_stage(TYPE "OIIO_PLUGIN" TARGET ${_target})
