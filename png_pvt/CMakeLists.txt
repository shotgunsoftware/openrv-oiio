#
# Copyright (C) 2022  Autodesk, Inc. All Rights Reserved.
#
# SPDX-License-Identifier: Apache-2.0
#

include(cxx_defaults)

set(_target "png_pvt")

add_library(${_target} INTERFACE IMPORTED GLOBAL)

set_target_properties(${_target} PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
                                            "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(${_target} INTERFACE OpenImageIO Imath::Imath png16
                                           ZLIB::ZLIB)
