#
# Copyright (C) 2022  Autodesk, Inc. All Rights Reserved.
#
# SPDX-License-Identifier: Apache-2.0
#

INCLUDE(cxx_defaults)

SET(_target
    "tiff.imageio"
)

LIST(APPEND _sources tiffinput.cpp tiffoutput.cpp)

ADD_LIBRARY(
  ${_target} SHARED
  ${_sources}
)

TARGET_LINK_LIBRARIES(
  ${_target}
  PRIVATE OpenImageIO tiff
)

RV_STAGE(TYPE "OIIO_PLUGIN" TARGET ${_target})
