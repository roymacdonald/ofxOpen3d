// ----------------------------------------------------------------------------
// -                        Open3D: www.open3d.org                            -
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2018-2021 www.open3d.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------------------------------------------------------

// PRIVATE RealSense header for compiling Open3D. Do not #include outside
// Open3D.
#pragma once

#include <librealsense2/rs.hpp>

#include "open3d/io/IJsonConvertibleIO.h"

namespace open3d {
namespace t {
namespace io {

DECLARE_STRINGIFY_ENUM(rs2_stream)
DECLARE_STRINGIFY_ENUM(rs2_format)
DECLARE_STRINGIFY_ENUM(rs2_l500_visual_preset)
DECLARE_STRINGIFY_ENUM(rs2_rs400_visual_preset)
DECLARE_STRINGIFY_ENUM(rs2_sr300_visual_preset)

}  // namespace io
}  // namespace t
}  // namespace open3d
